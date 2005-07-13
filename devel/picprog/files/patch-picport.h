--- picport.h.orig	Thu Apr 29 00:09:38 2004
+++ picport.h	Fri Jul  8 21:46:07 2005
@@ -59,6 +59,10 @@
 
 public:
 
+  static int t_on;
+  static int t_off;
+  static int t_edge;
+
   static void delay (long ns);
 
   enum commands {
