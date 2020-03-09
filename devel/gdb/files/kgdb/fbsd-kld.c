/*
 * Copyright (c) 2004 Marcel Moolenaar
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD$");

#include "defs.h"
#include "command.h"
#include "completer.h"
#include "environ.h"
#include "exec.h"
#include "frame-unwind.h"
#include "inferior.h"
#include "objfiles.h"
#include "gdbcore.h"
#include "language.h"
#include "solib.h"
#include "solist.h"

#include "kgdb.h"

struct lm_info_kld : public lm_info_base {
	CORE_ADDR base_address;
};

struct kld_info {
	/* Offsets of fields in linker_file structure. */
	CORE_ADDR off_address, off_filename, off_pathname, off_next;

	/* KVA of 'linker_path' which corresponds to the kern.module_path sysctl .*/
	CORE_ADDR module_path_addr;
	CORE_ADDR linker_files_addr;
	CORE_ADDR kernel_file_addr;
};

struct target_so_ops kld_so_ops;

/* Per-program-space data key.  */
static const struct program_space_data *kld_pspace_data;

static void
kld_pspace_data_cleanup (struct program_space *pspace, void *arg)
{
  struct kld_info *info = (struct kld_info *)arg;

  xfree (info);
}

/* Get the current kld data.  If none is found yet, add it now.  This
   function always returns a valid object.  */

static struct kld_info *
get_kld_info (void)
{
  struct kld_info *info;

  info = (struct kld_info *)
    program_space_data (current_program_space, kld_pspace_data);
  if (info != NULL)
    return info;

  info = XCNEW (struct kld_info);
  set_program_space_data (current_program_space, kld_pspace_data, info);
  return info;
}

static int
kld_ok (char *path)
{
	struct stat sb;

	if (stat(path, &sb) == 0 && S_ISREG(sb.st_mode))
		return (1);
	return (0);
}

/*
 * Look for a matching file checking for debug suffixes before the raw file:
 * - filename + ".debug" (e.g. foo.ko.debug)
 * - filename (e.g. foo.ko)
 */
static const char *kld_suffixes[] = {
	".debug",
	".symbols",
	"",
	NULL
};

static int
check_kld_path (char *path, size_t path_size)
{
	const char **suffix;
	char *ep;

	ep = path + strlen(path);
	suffix = kld_suffixes;
	while (*suffix != NULL) {
		if (strlcat(path, *suffix, path_size) < path_size) {
			if (kld_ok(path))
				return (1);
		}

		/* Restore original path to remove suffix. */
		*ep = '\0';
		suffix++;
	}
	return (0);
}

/*
 * Try to find the path for a kld by looking in the kernel's directory and
 * in the various paths in the module path.
 */
static int
find_kld_path (const char *filename, char *path, size_t path_size)
{
	struct kld_info *info;
	gdb::unique_xmalloc_ptr<char> module_path;
	char *module_dir, *cp;
	int error;

	info = get_kld_info();
	if (exec_bfd) {
		std::string kernel_dir = ldirname(bfd_get_filename(exec_bfd));
		if (!kernel_dir.empty()) {
			snprintf(path, path_size, "%s/%s", kernel_dir.c_str(),
			    filename);
			if (check_kld_path(path, path_size))
				return (1);
		}
	}
	if (info->module_path_addr != 0) {
		target_read_string(info->module_path_addr, &module_path,
		    PATH_MAX, &error);
		if (error == 0) {
			cp = module_path.get();
			while ((module_dir = strsep(&cp, ";")) != NULL) {
				snprintf(path, path_size, "%s/%s", module_dir,
				    filename);
				if (check_kld_path(path, path_size))
					return (1);
			}
		}
	}
	return (0);
}

/*
 * Read a kernel pointer given a KVA in 'address'.
 */
static CORE_ADDR
read_pointer (CORE_ADDR address)
{
	struct type *ptr_type;
	gdb_byte ptr_buf[8];
	int arch_size;

	arch_size = bfd_get_arch_size (exec_bfd);
	if (arch_size == -1)
		return (0);
	ptr_type = builtin_type (target_gdbarch ())->builtin_data_ptr;
	if (target_read_memory(address, ptr_buf, arch_size / 8) != 0)
		return (0);
	return (extract_typed_address (ptr_buf, ptr_type));
}

/*
 * Try to find this kld in the kernel linker's list of linker files.
 */
static int
find_kld_address (const char *arg, CORE_ADDR *address)
{
	struct kld_info *info;
	CORE_ADDR kld;
	gdb::unique_xmalloc_ptr<char> kld_filename;
	const char *filename;
	int error;

	info = get_kld_info();
	if (info->linker_files_addr == 0 || info->off_address == 0 ||
	    info->off_filename == 0 || info->off_next == 0)
		return (0);

	filename = lbasename(arg);
	for (kld = read_pointer(info->linker_files_addr); kld != 0;
	     kld = read_pointer(kld + info->off_next)) {
		/* Try to read this linker file's filename. */
		target_read_string(read_pointer(kld + info->off_filename),
		    &kld_filename, PATH_MAX, &error);
		if (error)
			continue;

		/* Compare this kld's filename against our passed in name. */
		if (strcmp(kld_filename.get(), filename) != 0)
			continue;

		/*
		 * We found a match, use its address as the base
		 * address if we can read it.
		 */
		*address = read_pointer(kld + info->off_address);
		if (*address == 0)
			return (0);
		return (1);
	}
	return (0);
}

static void
adjust_section_address (struct target_section *sec, CORE_ADDR *curr_base)
{
	struct bfd_section *asect = sec->the_bfd_section;
	bfd *abfd = asect->owner;

	if ((abfd->flags & (EXEC_P | DYNAMIC)) != 0) {
		sec->addr += *curr_base;
		sec->endaddr += *curr_base;
		return;
	}

	*curr_base = align_power(*curr_base,
	    bfd_section_alignment(asect));
	sec->addr = *curr_base;
	sec->endaddr = sec->addr + bfd_section_size(asect);
	*curr_base = sec->endaddr;
}

static void
load_kld (char *path, CORE_ADDR base_addr, int from_tty)
{
	struct target_section *sections = NULL, *sections_end = NULL, *s;
	gdb_bfd_ref_ptr bfd;
	CORE_ADDR curr_addr;
	symfile_add_flags add_flags;
	int i;

	/* Open the kld. */
	bfd = gdb_bfd_openr(path, gnutarget);
	if (bfd == NULL)
		error("\"%s\": can't open: %s", path,
		    bfd_errmsg(bfd_get_error()));

	if (!bfd_check_format(bfd.get(), bfd_object))
		error("\%s\": not an object file", path);

	/* Make sure we have a .text section. */
	if (bfd_get_section_by_name (bfd.get(), ".text") == NULL)
		error("\"%s\": can't find text section", path);

	/* Build a section table from the bfd and relocate the sections. */
	if (build_section_table (bfd.get(), &sections, &sections_end))
		error("\"%s\": can't find file sections", path);
	curr_addr = base_addr;
	for (s = sections; s < sections_end; s++)
		adjust_section_address(s, &curr_addr);

	/* Build a section addr info to pass to symbol_file_add(). */
	section_addr_info sap
	    = build_section_addr_info_from_section_table (sections,
		sections_end);
	xfree(sections);

	printf_unfiltered("add symbol table from file \"%s\" at\n", path);
	for (i = 0; i < sap.size(); i++)
		printf_unfiltered("\t%s_addr = %s\n", sap[i].name.c_str(),
		    paddress(target_gdbarch(), sap[i].addr));		

	if (from_tty && (!query("%s", "")))
		error("Not confirmed.");

	add_flags = 0;
	if (from_tty)
		add_flags |= SYMFILE_VERBOSE;
	symbol_file_add_from_bfd(bfd.get(), path, add_flags, &sap,
	    OBJF_USERLOADED, NULL);
}

static void
kgdb_add_kld_cmd (const char *arg, int from_tty)
{
	char path[PATH_MAX];
	CORE_ADDR base_addr;

	if (!exec_bfd)
		error("No kernel symbol file");

	/* Try to open the raw path to handle absolute paths first. */
	snprintf(path, sizeof(path), "%s", arg);
	if (!check_kld_path(path, sizeof(path))) {

		/*
		 * If that didn't work, look in the various possible
		 * paths for the module.
		 */
		if (!find_kld_path(arg, path, sizeof(path))) {
			error("Unable to locate kld");
			return;
		}
	}

	if (!find_kld_address(arg, &base_addr)) {
		error("Unable to find kld in kernel");
		return;
	}

	load_kld(path, base_addr, from_tty);

	reinit_frame_cache();
}

static void
kld_relocate_section_addresses (struct so_list *so, struct target_section *sec)
{
  lm_info_kld *li = (lm_info_kld *) so->lm_info;
  static CORE_ADDR curr_addr;

  if (sec == so->sections)
    curr_addr = li->base_address;

  adjust_section_address(sec, &curr_addr);
}

static void
kld_free_so (struct so_list *so)
{
  lm_info_kld *li = (lm_info_kld *) so->lm_info;

  delete li;
}

static void
kld_clear_so (struct so_list *so)
{
  lm_info_kld *li = (lm_info_kld *) so->lm_info;

  if (li != NULL)
    li->base_address = 0;
}

static void
kld_clear_solib (void)
{
	struct kld_info *info;

	info = get_kld_info();

	memset(info, 0, sizeof(*info));
}

static void
kld_solib_create_inferior_hook (int from_tty)
{
	struct kld_info *info;

	info = get_kld_info();
	
	/*
	 * Compute offsets of relevant members in struct linker_file
	 * and the addresses of global variables.  Newer kernels
	 * include constants we can use without requiring debug
	 * symbols.
	 */
	try {
		info->off_address = parse_and_eval_long("kld_off_address");
		info->off_filename = parse_and_eval_long("kld_off_filename");
		info->off_pathname = parse_and_eval_long("kld_off_pathname");
		info->off_next = parse_and_eval_long("kld_off_next");
	} catch (const gdb_exception_error &e) {
		try {
			struct symbol *linker_file_sym =
			    lookup_symbol_in_language ("struct linker_file",
				NULL, STRUCT_DOMAIN, language_c, NULL).symbol;
			if (linker_file_sym == NULL)
				error (_(
			    "Unable to find struct linker_file symbol"));

			info->off_address =
			    lookup_struct_elt (SYMBOL_TYPE (linker_file_sym),
				"address", 0).offset / 8;
			info->off_filename =
			    lookup_struct_elt (SYMBOL_TYPE (linker_file_sym),
				"filename", 0).offset / 8;
			info->off_pathname =
			    lookup_struct_elt (SYMBOL_TYPE (linker_file_sym),
				"pathname", 0).offset / 8;

			struct type *link_type =
			    lookup_struct_elt_type (SYMBOL_TYPE (linker_file_sym),
				"link", 0);
			if (link_type == NULL)
				error (_("Unable to find link type"));

			info->off_next =
			    lookup_struct_elt (link_type, "tqe_next",
				0).offset / 8;
		} catch (const gdb_exception_error &e2) {
			return;
		}
	}

	try {
		info->module_path_addr = parse_and_eval_address("linker_path");
		info->linker_files_addr = kgdb_lookup("linker_files");
		info->kernel_file_addr = kgdb_lookup("linker_kernel_file");
	} catch (const gdb_exception_error &e) {
		return;
	}

	solib_add(NULL, from_tty, auto_solib_add);
}

static struct so_list *
kld_current_sos (void)
{
	struct so_list *head, **prev, *newobj;
	struct kld_info *info;
	CORE_ADDR kld, kernel;
	gdb::unique_xmalloc_ptr<char> path;
	int error;

	info = get_kld_info();
	if (info->linker_files_addr == 0 || info->kernel_file_addr == 0 ||
	    info->off_address == 0 || info->off_filename == 0 ||
	    info->off_next == 0)
		return (NULL);

	head = NULL;
	prev = &head;

	/*
	 * Walk the list of linker files creating so_list entries for
	 * each non-kernel file.
	 */
	kernel = read_pointer(info->kernel_file_addr);
	for (kld = read_pointer(info->linker_files_addr); kld != 0;
	     kld = read_pointer(kld + info->off_next)) {
		/* Skip the main kernel file. */
		if (kld == kernel)
			continue;

		newobj = XCNEW (struct so_list);

		lm_info_kld *li = new lm_info_kld;
		li->base_address = 0;

		newobj->lm_info = li;

		/* Read the base filename and store it in so_original_name. */
		target_read_string(read_pointer(kld + info->off_filename),
		    &path, sizeof(newobj->so_original_name), &error);
		if (error != 0) {
			warning("kld_current_sos: Can't read filename: %s\n",
			    safe_strerror(error));
			free_so(newobj);
			continue;
		}
		strlcpy(newobj->so_original_name, path.get(),
		    sizeof(newobj->so_original_name));

		/*
		 * Try to read the pathname (if it exists) and store
		 * it in so_name.
		 */
		if (find_kld_path(newobj->so_original_name, newobj->so_name,
		    sizeof(newobj->so_name))) {
			/* we found the kld */;
		} else if (info->off_pathname != 0) {
			target_read_string(read_pointer(kld +
			    info->off_pathname),
			    &path, sizeof(newobj->so_name), &error);
			if (error != 0) {
				warning(
		    "kld_current_sos: Can't read pathname for \"%s\": %s\n",
				    newobj->so_original_name,
				    safe_strerror(error));
				strlcpy(newobj->so_name, newobj->so_original_name,
				    sizeof(newobj->so_name));
			} else {
				strlcpy(newobj->so_name, path.get(),
				    sizeof(newobj->so_name));
			}
		} else
			strlcpy(newobj->so_name, newobj->so_original_name,
			    sizeof(newobj->so_name));

		/* Read this kld's base address. */
		li->base_address = read_pointer(kld + info->off_address);
		if (li->base_address == 0) {
			warning(
			    "kld_current_sos: Invalid address for kld \"%s\"",
			    newobj->so_original_name);
			free_so(newobj);
			continue;
		}

		/* Append to the list. */
		*prev = newobj;
		prev = &newobj->next;
	}

	return (head);
}

static int
kld_open_symbol_file_object (int from_tty)
{

	return (0);
}

static int
kld_in_dynsym_resolve_code (CORE_ADDR pc)
{

	return (0);
}

static int
kld_find_and_open_solib (const char *solib, unsigned o_flags,
    gdb::unique_xmalloc_ptr<char> *temp_pathname)
{
	char path[PATH_MAX];
	int fd;

	temp_pathname->reset (NULL);
	if (!find_kld_path(solib, path, sizeof(path))) {
		errno = ENOENT;
		return (-1);
	}
	fd = open(path, o_flags, 0);
	if (fd >= 0)
		temp_pathname->reset(xstrdup(path));
	return (fd);
}

void
_initialize_kld_target(void)
{
	struct cmd_list_element *c;

	kld_so_ops.relocate_section_addresses = kld_relocate_section_addresses;
	kld_so_ops.free_so = kld_free_so;
	kld_so_ops.clear_so = kld_clear_so;
	kld_so_ops.clear_solib = kld_clear_solib;
	kld_so_ops.solib_create_inferior_hook = kld_solib_create_inferior_hook;
	kld_so_ops.current_sos = kld_current_sos;
	kld_so_ops.open_symbol_file_object = kld_open_symbol_file_object;
	kld_so_ops.in_dynsym_resolve_code = kld_in_dynsym_resolve_code;
	kld_so_ops.bfd_open = solib_bfd_open;
	kld_so_ops.find_and_open_solib = kld_find_and_open_solib;

	c = add_com("add-kld", class_files, kgdb_add_kld_cmd,
	   "Usage: add-kld FILE\n\
Load the symbols from the kernel loadable module FILE.");
	set_cmd_completer(c, filename_completer);

	kld_pspace_data = register_program_space_data_with_cleanup (NULL,
	    kld_pspace_data_cleanup);
}
