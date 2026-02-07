--- lib/lib/xneur.h.orig	2020-06-21 16:29:31 UTC
+++ lib/lib/xneur.h
@@ -32,7 +32,7 @@
 #	include <enchant/enchant.h>
 #endif
 
-struct _window *main_window;
+extern struct _window *main_window;
 
 struct _xneur_language
 {
