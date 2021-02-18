--- dwz.c.orig	2019-10-02 10:26:03.015230341 -0400
+++ dwz.c	2020-04-05 14:12:16.054408000 -0400
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
@@ -34,7 +34,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 
-#include <obstack.h>
+#include "obstack.h"
 
 #include <gelf.h>
 #include "dwarf2.h"
@@ -136,6 +136,29 @@ dwz_oom (void)
   longjmp (oom_buf, 1);
 }
 
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
 /* General obstack for struct dw_cu, dw_die, also used for temporary
    vectors.  */
 static struct obstack ob;
@@ -10300,7 +10323,7 @@ fdopen_dso (int fd, const char *name)
   int i;
   DSO *dso = NULL;
 
-  elf = elf_begin (fd, ELF_C_READ_MMAP, NULL);
+  elf = elf_begin (fd, ELF_C_READ, NULL);
   if (elf == NULL)
     {
       error (0, 0, "cannot open ELF file: %s", elf_errmsg (-1));
@@ -10338,7 +10361,7 @@ fdopen_dso (int fd, const char *name)
       goto error_out;
     }
 
-  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT | ELF_F_PERMISSIVE);
+  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT);
 
   memset (dso, 0, sizeof(DSO));
   dso->elf = elf;
@@ -10829,7 +10852,7 @@ write_dso (DSO *dso, const char *file, struct stat *st
       free (shstrtab);
       return 1;
     }
-  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT | ELF_F_PERMISSIVE);
+  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT);
   for (i = 0; i < ehdr.e_phnum; ++i)
     {
       GElf_Phdr *phdr, phdr_mem;
@@ -10902,7 +10925,7 @@ write_dso (DSO *dso, const char *file, struct stat *st
 	}
     }
 
-  if (elf_update (elf, ELF_C_WRITE_MMAP) == -1)
+  if (elf_update (elf, ELF_C_WRITE) == -1)
     {
       error (0, 0, "%s: elf_update failed", dso->filename);
       unlink (file);
@@ -12089,7 +12112,7 @@ optimize_multifile (void)
       error (0, 0, "Could not create new ELF headers");
       goto fail;
     }
-  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT | ELF_F_PERMISSIVE);
+  elf_flagelf (elf, ELF_C_SET, ELF_F_LAYOUT);
 
   sha1_init_ctx (&ctx);
   for (i = 0; debug_sections[i].name; i++)
@@ -12176,7 +12199,7 @@ optimize_multifile (void)
   data->d_off = 0;
   data->d_align = 1;
 
-  if (elf_update (elf, ELF_C_WRITE_MMAP) == -1)
+  if (elf_update (elf, ELF_C_WRITE) == -1)
     {
       error (0, 0, "%s: elf_update failed", multifile);
       goto fail;
