--- ../sysui/unix/office/gnome/gnome-vfs-filetype-registration.cxx.orig	Tue Mar 11 12:43:34 2003
+++ ../sysui/unix/office/gnome/gnome-vfs-filetype-registration.cxx	Tue Mar 11 12:43:58 2003
@@ -62,7 +62,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <dlfcn.h>
+#if !(defined FREEBSD || defined NETBSD)
 #include <alloca.h>
+#endif
 #include <string.h>
 
 /* 
