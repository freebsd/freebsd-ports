--- picport.h.orig	Wed Jul 14 01:24:34 2004
+++ picport.h	Fri Dec 15 16:43:35 2006
@@ -45,7 +45,7 @@
   int W[16];
 
   int modembits;
-  void picport::set_clock_data (int rts, int dtr);
+  void set_clock_data (int rts, int dtr);
 
   void p_out (int b);
   int p_in ();
@@ -58,6 +58,10 @@
   static int use_nanosleep;
 
 public:
+
+  static int t_on;
+  static int t_off;
+  static int t_edge;
 
   static void delay (long ns);
 
