$FreeBSD$

--- bsdtar.c.orig	Mon Sep  5 20:04:11 2005
+++ bsdtar.c	Mon Sep  5 20:06:03 2005
@@ -29,6 +29,7 @@
 
 #include <sys/param.h>
 #include <sys/stat.h>
+#include <wchar.h>
 #include <archive.h>
 #include <archive_entry.h>
 #include <errno.h>
