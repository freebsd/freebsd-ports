--- gnome-initial-setup/gnome-initial-setup-copy-worker.c.orig	2025-03-14 10:45:52 UTC
+++ gnome-initial-setup/gnome-initial-setup-copy-worker.c
@@ -11,6 +11,7 @@
 #define _POSIX_C_SOURCE 200809L
 #endif
 
+#define __XSI_VISIBLE 1
 #include <pwd.h>
 #include <string.h>
 #include <locale.h>
@@ -20,6 +21,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/types.h>
+#include <time.h>
 #include <sys/stat.h>
 #ifdef HAVE_XATTR
 #include <sys/xattr.h>
