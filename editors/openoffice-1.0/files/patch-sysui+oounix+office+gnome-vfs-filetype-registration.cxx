--- ../sysui/oounix/office/gnome/gnome-vfs-filetype-registration.cxx.orig	Wed May  1 23:45:49 2002
+++ ../sysui/oounix/office/gnome/gnome-vfs-filetype-registration.cxx	Wed May  1 23:48:17 2002
@@ -62,7 +62,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <dlfcn.h>
+#if !(defined NETBSD || defined FREEBSD)
 #include <alloca.h>
+#endif
 #include <string.h>
 
 /* 
