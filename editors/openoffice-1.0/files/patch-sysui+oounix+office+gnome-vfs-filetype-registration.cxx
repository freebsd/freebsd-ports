--- sysui/oounix/office/gnome/gnome-vfs-filetype-registration.cxx.orig	Fri Aug 16 18:56:19 2002
+++ sysui/oounix/office/gnome/gnome-vfs-filetype-registration.cxx	Sat Jan 18 13:06:16 2003
@@ -62,7 +62,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <dlfcn.h>
-#ifndef MACOSX
+#if !(defined NETBSD || defined FREEBSD || defined MACOSX)
 #include <alloca.h>
 #endif
 #include <string.h>
