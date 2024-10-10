--- src/afuse.c.orig	2013-02-13 02:36:47 UTC
+++ src/afuse.c
@@ -29,7 +29,7 @@
 #include <string.h>
 #include <stddef.h>
 #include <unistd.h>
-#include <alloca.h>
+//#include <alloca.h>
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
