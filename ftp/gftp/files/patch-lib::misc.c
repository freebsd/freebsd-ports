--- lib/misc.c.orig	Sat Nov  8 13:23:20 2003
+++ lib/misc.c	Mon Nov 10 18:45:34 2003
@@ -21,8 +21,9 @@
 
 #include "gftp.h"
 #include "options.h"
+#include "osreldate.h"
 
-#ifdef _GNU_SOURCE
+#if defined(_GNU_SOURCE) && __FreeBSD_version > 500000
 
 char *
 insert_commas (off_t number, char *dest_str, size_t dest_len)
