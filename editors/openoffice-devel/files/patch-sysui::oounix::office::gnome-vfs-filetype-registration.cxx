--- ../sysui/oounix/office/gnome/gnome-vfs-filetype-registration.cxx.orig	Wed Aug 28 14:10:06 2002
+++ ../sysui/oounix/office/gnome/gnome-vfs-filetype-registration.cxx	Fri Oct 18 22:45:43 2002
@@ -62,7 +62,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <dlfcn.h>
-#ifndef MACOSX
+#if !(defined NETBSD || defined FREEBSD || defined MACOSX)
 #include <alloca.h>
 #endif
 #include <string.h>
