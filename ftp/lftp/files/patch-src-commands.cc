--- src/commands.cc.orig	2008-11-17 01:34:09.000000000 +0800
+++ src/commands.cc	2008-11-17 01:34:19.000000000 +0800
@@ -31,6 +31,7 @@
 #include <pwd.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 #include <fcntl.h>
 #include <assert.h>
 #ifdef HAVE_DLFCN_H
