--- dwz.c.orig	2021-03-09 22:33:26 UTC
+++ dwz.c
@@ -20,11 +20,11 @@
 
 #include <assert.h>
 #include <errno.h>
-#include <error.h>
 #include <fcntl.h>
 #include <getopt.h>
 #include <setjmp.h>
 #include <string.h>
+#include <stdarg.h>
 #include <stdbool.h>
 #include <stddef.h>
 #include <stdint.h>
@@ -36,7 +36,7 @@
 #include <sys/types.h>
 #include <sys/times.h>
 
-#include <obstack.h>
+#include "obstack.h"
 
 #include <gelf.h>
 #include "dwarf2.h"
@@ -165,6 +165,29 @@ report_progress (void)
 /* Where to longjmp on OOM.  */
 static jmp_buf oom_buf;
 
+/* error () wrapper based on the Linux manual page at
+   http://man7.org/linux/man-pages/man3/error.3.html.  */
+static void
+error (int status, int errnum, const char *fmt, ...)
+{
+  va_list ap;
+
+  fprintf (stderr, "%s: ", getprogname());
+  if (fmt != NULL) {
+    va_start (ap, fmt);
+    vfprintf (stderr, fmt, ap);
+    va_end (ap);
+  }
+
+  if (errnum != 0)
+    fprintf (stderr, ": %s", strerror(errnum));
+
+  fputc ('\n', stderr);
+
+  if (status != 0)
+    exit (status);
+}
+
 /* Handle OOM situation.  If handling more than one file, we might
    just fail to handle some large file due to OOM, but could very well
    handle other smaller files after it.  */
@@ -13723,7 +13746,7 @@ fdopen_dso (int fd, const char *name)
   int i;
   DSO *dso = NULL;
 
-  elf = elf_begin (fd, ELF_C_READ_MMAP, NULL);
+  elf = elf_begin (fd, ELF_C_READ, NULL);
   if (elf == NULL)
     {
       error (0, 0, "cannot open ELF file: %s", elf_errmsg (-1));
@@ -13761,7 +13784,7 @@ fdopen_dso (int fd, const char *name)
       goto error_out;
     }
 
-  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT | ELF_F_PERMISSIVE);
+  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT);
 
   memset (dso, 0, sizeof(DSO));
   dso->elf = elf;
@@ -14258,7 +14281,7 @@ write_dso (DSO *dso, const char *file, struct stat *st
       free (shstrtab);
       return 1;
     }
-  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT | ELF_F_PERMISSIVE);
+  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT);
   for (i = 0; i < ehdr.e_phnum; ++i)
     {
       GElf_Phdr *phdr, phdr_mem;
@@ -14331,7 +14354,7 @@ write_dso (DSO *dso, const char *file, struct stat *st
 	}
     }
 
-  if (elf_update (elf, ELF_C_WRITE_MMAP) == -1)
+  if (elf_update (elf, ELF_C_WRITE) == -1)
     {
       error (0, 0, "%s: elf_update failed", dso->filename);
       unlink (file);
@@ -15917,7 +15940,7 @@ optimize_multifile (unsigned int *die_count)
       error (0, 0, "Could not create new ELF headers");
       goto fail;
     }
-  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT | ELF_F_PERMISSIVE);
+  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT);
 
   sha1_init_ctx (&ctx);
   for (i = 0; debug_sections[i].name; i++)
@@ -16010,7 +16033,7 @@ optimize_multifile (unsigned int *die_count)
   data->d_off = 0;
   data->d_align = 1;
 
-  if (elf_update (elf, ELF_C_WRITE_MMAP) == -1)
+  if (elf_update (elf, ELF_C_WRITE) == -1)
     {
       error (0, 0, "%s: elf_update failed", multifile);
       goto fail;
