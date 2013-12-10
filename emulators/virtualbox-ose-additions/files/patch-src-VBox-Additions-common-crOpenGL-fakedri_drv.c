--- src/VBox/Additions/common/crOpenGL/fakedri_drv.c.orig	2013-11-28 19:30:42.000000000 +0100
+++ src/VBox/Additions/common/crOpenGL/fakedri_drv.c	2013-12-06 16:03:16.000000000 +0100
@@ -29,6 +29,15 @@
 #include <dlfcn.h>
 #include <elf.h>
 #include <unistd.h>
+
+#include <sys/param.h>
+#if defined(BSD)
+#include <fcntl.h>
+#include <gelf.h>
+#include <libelf.h>
+#include <string.h>
+#endif
+
 /** X server message type definitions. */
 typedef enum {
     X_PROBED,			/* Value was probed */
@@ -50,11 +59,11 @@
 
 //@todo this could be different...
 #ifdef RT_ARCH_AMD64
-# define DRI_DEFAULT_DRIVER_DIR "/usr/lib64/dri:/usr/lib/dri:/usr/lib/x86_64-linux-gnu/dri:/usr/lib/xorg/modules/dri"
-# define DRI_XORG_DRV_DIR "/usr/lib/xorg/modules/drivers/"
+# define DRI_DEFAULT_DRIVER_DIR "/usr/local/lib/dri"
+# define DRI_XORG_DRV_DIR "/usr/local/lib/xorg/modules/drivers/"
 #else
-# define DRI_DEFAULT_DRIVER_DIR "/usr/lib/dri:/usr/lib/i386-linux-gnu/dri:/usr/lib/xorg/modules/dri"
-# define DRI_XORG_DRV_DIR "/usr/lib/xorg/modules/drivers/"
+# define DRI_DEFAULT_DRIVER_DIR "/usr/local/lib/dri"
+# define DRI_XORG_DRV_DIR "/usr/local/lib/xorg/modules/drivers/"
 #endif
 
 #ifdef DEBUG_DRI_CALLS
@@ -209,6 +218,85 @@
 
 #define FAKEDRI_JMP64_PATCH_SIZE 13
 
+#if defined(BSD)
+/* Provide basic dladdr1 flags */
+enum {
+	RTLD_DL_SYMENT	= 1
+};
+
+/* Provide a minimal local version of dladdr1 */
+static int
+dladdr1(const void *address, Dl_info *dlip, void **info, int flags)
+{
+	static DRI_ELFSYM desym;
+	GElf_Sym sym;
+	GElf_Shdr shdr;
+	Elf *elf;
+	Elf_Scn *scn;
+	Elf_Data *data;
+	int ret, fd, count, i;
+
+	/* Initialize variables */
+	fd = -1;
+	elf = NULL;
+
+	/* Call dladdr first */
+	ret = dladdr(address, dlip);
+	if (ret == 0) goto err_exit;
+
+	/* Check for supported flags */
+	if (flags != RTLD_DL_SYMENT) return 1;
+
+	/* Open shared library's ELF file */
+	if (elf_version(EV_CURRENT) == EV_NONE) goto err_exit;
+	fd = open(dlip->dli_fname, O_RDONLY);
+	if (fd < 0) goto err_exit;
+	elf = elf_begin(fd, ELF_C_READ, NULL);
+	if (elf == NULL) goto err_exit;
+
+	/* Find the '.dynsym' section */
+	scn = elf_nextscn(elf, NULL);
+	while (scn != NULL) {
+		if (gelf_getshdr(scn, &shdr) == NULL) goto err_exit;
+		if (shdr.sh_type == SHT_DYNSYM) break;
+		scn = elf_nextscn(elf, scn);
+	}
+	if (scn == NULL) goto err_exit;
+
+	/* Search for the requested symbol by name and offset */
+	data = elf_getdata(scn, NULL);
+	count = shdr.sh_size / shdr.sh_entsize;
+	for (i = 0; i < count; i++) {
+		gelf_getsym(data, i, &sym);
+		if ((strcmp(dlip->dli_sname,
+		        elf_strptr(elf, shdr.sh_link, sym.st_name)) == 0) &&
+		    (sym.st_value == (dlip->dli_saddr - dlip->dli_fbase))) {
+			break;
+		}
+	}
+
+	/* Close ELF file */
+	elf_end(elf);
+	close(fd);
+
+	/* Return symbol entry in native format */
+	desym.st_name = sym.st_name;
+	desym.st_info = sym.st_info;
+	desym.st_other = sym.st_other;
+	desym.st_shndx = sym.st_shndx;
+	desym.st_value = sym.st_value;
+	desym.st_size = sym.st_size;
+	*info = &desym;
+	return 1;
+
+	/* Error handler */
+err_exit:
+	if (elf != NULL) elf_end(elf);
+	if (fd >= 0) close(fd);
+	return 0;
+}
+#endif
+
 static void
 vboxPatchMesaExport(const char* psFuncName, const void *pStart, const void *pEnd)
 {
