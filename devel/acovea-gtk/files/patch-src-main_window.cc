diff -urN src.orig/main_window.cc src/main_window.cc
--- src.orig/main_window.cc	Tue Aug  1 20:45:30 2006
+++ src/main_window.cc	Tue Aug  1 20:49:57 2006
@@ -5,6 +5,8 @@
 
 // This file is for your program, I won't touch it again!
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <glibmm/thread.h>
 #include <gtkmm.h>
 #include <gtkmm/main.h>
