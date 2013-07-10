--- ucon64_misc.c.orig	2013-02-24 22:48:15.577943937 -0800
+++ ucon64_misc.c	2013-02-24 22:51:28.521008805 -0800
@@ -1698,7 +1698,7 @@
 #elif   defined __APPLE__                       // Mac OS X actually
         "~/.ucon64/discmage.dylib",
 #elif   defined __unix__ || defined __BEOS__
-        "~/.ucon64/discmage.so",
+        "%%PREFIX%%/lib/libdiscmage.so",
 #else
         "",
 #endif
