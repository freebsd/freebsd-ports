--- make/bsd/bsd.cc.orig	2023-01-13 17:10:06 UTC
+++ make/bsd/bsd.cc
@@ -50,7 +50,7 @@
 extern SIG_PF
 bsdsignal (int Signal, SIG_PF Handler)
 {
-  auto SIG_PF                   previous_handler;
+  SIG_PF                   previous_handler;
 #ifdef SUN5_0
 #ifdef sun
   previous_handler = sigset (Signal, Handler);
