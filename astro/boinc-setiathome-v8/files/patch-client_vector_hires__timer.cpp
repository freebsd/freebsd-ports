--- client/vector/hires_timer.cpp.orig	2018-01-14 21:26:29 UTC
+++ client/vector/hires_timer.cpp
@@ -267,7 +267,7 @@ hires_timer::hires_timer() : rollover(0),last_ticks(0)
 #endif
   if (period==0) {
     install_sighandler();
-    if (setjmp(jb)) {
+    if (sigsetjmp(jb,0)) {
       fprintf(stderr,"using fallback timer\n");
       use_fallback=1;
     } else {
