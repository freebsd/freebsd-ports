--- ../sysui/unix/office/gnome/gnome-vfs-filetype-registration.cxx.orig	Wed Apr 10 21:54:49 2002
+++ ../sysui/unix/office/gnome/gnome-vfs-filetype-registration.cxx	Wed May  1 22:40:02 2002
@@ -62,7 +62,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <dlfcn.h>
-#if !defined(NETBSD)
+#if !(defined NETBSD || defined FREEBSD)
 #include <alloca.h>
 #endif
 #include <string.h>
