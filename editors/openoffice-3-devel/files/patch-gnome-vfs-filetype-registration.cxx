--- ../sysui/unix/office/gnome/gnome-vfs-filetype-registration.cxx	2001/11/01 13:26:23	1.2
+++ ../sysui/unix/office/gnome/gnome-vfs-filetype-registration.cxx	2002/03/03 19:43:31
@@ -62,7 +62,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <dlfcn.h>
+#if !defined(FREEBSD)
 #include <alloca.h>
+#endif
 #include <string.h>
 
 /* 
