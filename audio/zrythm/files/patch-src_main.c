--- src/main.c.orig	2020-05-26 06:54:40 UTC
+++ src/main.c
@@ -505,8 +505,8 @@ main (int    argc,
 
   /* init fftw */
   g_message ("Making fftw planner thread safe...");
-  fftw_make_planner_thread_safe ();
-  fftwf_make_planner_thread_safe ();
+  //fftw_make_planner_thread_safe ();
+  //fftwf_make_planner_thread_safe ();
 
   /* init audio decoder */
   g_message ("Initing audio decoder...");
