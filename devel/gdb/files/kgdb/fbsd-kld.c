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

#include "defs.h"
#include "command.h"
#include "completer.h"
#include "environ.h"
#include "exec.h"
#include "extract-store-integer.h"
#include "frame-unwind.h"
#include "inferior.h"
#include "objfiles.h"
#include "gdbcore.h"
#include "language.h"
#include "solib.h"
#include "solist.h"

#include "kgdb.h"

struct lm_info_kld final : public lm_info {
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

solib_ops kld_so_ops;

/* Per-program-space data key.  */
static const registry<program_space>::key<kld_info> kld_pspace_data;

/* Get the current kld data.  If none is found yet, add it now.  This
   function always returns a valid object.  */

static struct kld_info *
get_kld_info (program_space *pspace)
{
  struct kld_info *info;

  info = kld_pspace_data.get (pspace);
  if (info == nullptr)
    info = kld_pspace_data.emplace (pspace);

  return info;
}

static int
kld_ok (const char *path)
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
};

static bool
check_kld_path (std::string &path)
{
  for (const char *suffix : kld_suffixes) {
    std::string new_path = path + suffix;
    if (kld_ok (new_path.c_str ())) {
      path = new_path;
      return true;
    }
  }
  return false;
}

/*
 * Try to find the path for a kld by looking in the kernel's directory and
 * in the various paths in the module path.
 */
static std::optional<std::string>
find_kld_path (const char *filename)
{
  bfd *exec_bfd = current_program_space->exec_bfd ();
  if (exec_bfd != nullptr)
    {
      std::string kernel_dir = ldirname (bfd_get_filename (exec_bfd));
      if (!kernel_dir.empty ())
	{
	  std::string path = string_printf("%s/%s", kernel_dir.c_str (),
					   filename);
	  if (check_kld_path (path))
	    return path;
	}
    }

  struct kld_info *info = get_kld_info (current_program_space);
  if (info->module_path_addr != 0)
    {
      gdb::unique_xmalloc_ptr<char> module_path
	= target_read_string(info->module_path_addr, PATH_MAX);

      if (module_path != nullptr)
	{
	  char *cp = module_path.get();
	  char *module_dir;
	  while ((module_dir = strsep(&cp, ";")) != NULL)
	    {
	      std::string path = string_printf("%s/%s", module_dir, filename);
	      if (check_kld_path (path))
		return path;
	    }
	}
    }

  return {};
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

	arch_size = bfd_get_arch_size (current_program_space->exec_bfd ());
	if (arch_size == -1)
		return (0);
	ptr_type = builtin_type (current_inferior ()->arch ())->builtin_data_ptr;
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
	struct kld_info *info = get_kld_info(current_program_space);
	if (info->linker_files_addr == 0 || info->off_address == 0 ||
	    info->off_filename == 0 || info->off_next == 0)
		return (0);

	const char *filename = lbasename(arg);
	for (CORE_ADDR kld = read_pointer(info->linker_files_addr); kld != 0;
	     kld = read_pointer(kld + info->off_next)) {
		/* Try to read this linker file's filename. */
		gdb::unique_xmalloc_ptr<char> kld_filename =
		    target_read_string (read_pointer (kld + info->off_filename),
		    PATH_MAX);
		if (kld_filename == nullptr)
			continue;

		/* Compare this kld's filename against our passed in name. */
		if (strcmp(kld_filename.get (), filename) != 0)
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
load_kld (const char *path, CORE_ADDR base_addr, int from_tty)
{
	/* Open the kld. */
	gdb_bfd_ref_ptr bfd = gdb_bfd_openr(path, gnutarget);
	if (bfd == NULL)
		error("\"%s\": can't open: %s", path,
		    bfd_errmsg(bfd_get_error()));

	if (!bfd_check_format(bfd.get(), bfd_object))
		error("\%s\": not an object file", path);

	/* Make sure we have a .text section. */
	if (bfd_get_section_by_name (bfd.get(), ".text") == NULL)
		error("\"%s\": can't find text section", path);

	/* Build a section table from the bfd and relocate the sections. */
	std::vector<target_section> sections = build_section_table (bfd.get());
	CORE_ADDR curr_addr = base_addr;
	for (target_section &s : sections)
		adjust_section_address(&s, &curr_addr);

	/* Build a section addr info to pass to symbol_file_add(). */
	section_addr_info sap
	    = build_section_addr_info_from_section_table (sections);

	printf_unfiltered("add symbol table from file \"%s\" at\n", path);
	for (const other_sections &s : sap)
		printf_unfiltered("\t%s_addr = %s\n", s.name.c_str(),
		    paddress(current_inferior ()->arch (), s.addr));

	if (from_tty && (!query("%s", "")))
		error("Not confirmed.");

	symfile_add_flags add_flags = 0;
	if (from_tty)
		add_flags |= SYMFILE_VERBOSE;
	symbol_file_add_from_bfd(bfd, path, add_flags, &sap,
	    OBJF_USERLOADED, NULL);
}

static void
kgdb_add_kld_cmd (const char *arg, int from_tty)
{
	CORE_ADDR base_addr;

	if (current_program_space->exec_bfd () == nullptr)
		error("No kernel symbol file");

	/* Try to open the raw path to handle absolute paths first. */
	std::string path (arg);
	if (!check_kld_path(path)) {

		/*
		 * If that didn't work, look in the various possible
		 * paths for the module.
		 */
		std::optional<std::string> found = find_kld_path (arg);
		if (!found) {
			error("Unable to locate kld");
			return;
		}
		path = std::move(*found);
	}

	if (!find_kld_address(arg, &base_addr)) {
		error("Unable to find kld in kernel");
		return;
	}

	load_kld(path.c_str (), base_addr, from_tty);

	reinit_frame_cache();
}

static void
kld_relocate_section_addresses (solib &so, struct target_section *sec)
{
  auto *li = gdb::checked_static_cast<lm_info_kld *> (so.lm_info.get ());
  static CORE_ADDR curr_addr;

  if (sec == &so.sections.front())
    curr_addr = li->base_address;

  adjust_section_address (sec, &curr_addr);
}

static void
kld_clear_so (const solib &so)
{
  auto *li = gdb::checked_static_cast<lm_info_kld *> (so.lm_info.get ());

  if (li != NULL)
    li->base_address = 0;
}

static void
kld_clear_solib (program_space *pspace)
{
  kld_info *info = get_kld_info (pspace);

  memset(info, 0, sizeof(*info));
}

static void
kld_solib_create_inferior_hook (int from_tty)
{
	struct kld_info *info;

	info = get_kld_info (current_program_space);

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
				NULL, SEARCH_TYPE_DOMAIN, language_c, NULL).symbol;
			if (linker_file_sym == NULL)
				error (_(
			    "Unable to find struct linker_file symbol"));

			info->off_address =
			    lookup_struct_elt (linker_file_sym->type (),
				"address", 0).offset / 8;
			info->off_filename =
			    lookup_struct_elt (linker_file_sym->type (),
				"filename", 0).offset / 8;
			info->off_pathname =
			    lookup_struct_elt (linker_file_sym->type (),
				"pathname", 0).offset / 8;

			struct type *link_type =
			    lookup_struct_elt_type (linker_file_sym->type (),
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

static intrusive_list<solib>
kld_current_sos (void)
{
	struct kld_info *info = get_kld_info(current_program_space);
	if (info->linker_files_addr == 0 || info->kernel_file_addr == 0 ||
	    info->off_address == 0 || info->off_filename == 0 ||
	    info->off_next == 0)
		return {};

	intrusive_list<solib> sos;

	/*
	 * Walk the list of linker files creating solib entries for
	 * each non-kernel file.
	 */
	CORE_ADDR kernel = read_pointer(info->kernel_file_addr);
	for (CORE_ADDR kld = read_pointer(info->linker_files_addr); kld != 0;
	     kld = read_pointer(kld + info->off_next)) {
		/* Skip the main kernel file. */
		if (kld == kernel)
			continue;

		solib *newobj = new solib;

		auto li = std::make_unique<lm_info_kld> ();
		li->base_address = 0;

		/* Read the base filename and store it in so_original_name. */
		gdb::unique_xmalloc_ptr<char> filename =
		    target_read_string (read_pointer (kld + info->off_filename),
		    SO_NAME_MAX_PATH_SIZE - 1);
		if (filename == nullptr) {
			warning("kld_current_sos: Can't read filename\n");
			delete newobj;
			continue;
		}
		newobj->so_original_name = filename.get ();

		/*
		 * Try to read the pathname (if it exists) and store
		 * it in so_name.
		 */
		if (info->off_pathname != 0) {
			gdb::unique_xmalloc_ptr<char> path =
			  target_read_string (read_pointer (kld +
			  info->off_pathname), SO_NAME_MAX_PATH_SIZE - 1);
			if (path == nullptr) {
				warning(
		    "kld_current_sos: Can't read pathname for \"%s\"\n",
				    newobj->so_original_name.c_str ());
				newobj->so_name = newobj->so_original_name;
			} else {
				newobj->so_name = path.get();
			}
		} else
			newobj->so_name = newobj->so_original_name;

		/* Read this kld's base address. */
		li->base_address = read_pointer(kld + info->off_address);
		if (li->base_address == 0) {
			warning(
			    "kld_current_sos: Invalid address for kld \"%s\"",
			    newobj->so_original_name.c_str ());
			delete newobj;
			continue;
		}

		newobj->lm_info = std::move (li);
		sos.push_back (*newobj);
	}

	return sos;
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
  temp_pathname->reset (NULL);
  std::optional<std::string> found = find_kld_path (solib);
  if (!found) {
    errno = ENOENT;
    return (-1);
  }
  int fd = open(found->c_str (), o_flags, 0);
  if (fd >= 0)
    temp_pathname->reset (xstrdup (found->c_str ()));
  return (fd);
}

void _initialize_kld_target ();
void
_initialize_kld_target ()
{
	struct cmd_list_element *c;

	kld_so_ops.relocate_section_addresses = kld_relocate_section_addresses;
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
}
