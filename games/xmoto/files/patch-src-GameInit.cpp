--- src/GameInit.cpp.orig	2011-04-03 19:46:59.000000000 +0400
+++ src/GameInit.cpp	2011-05-07 12:50:13.000000000 +0400
@@ -260,7 +260,7 @@
     struct sigaction v_act;
 
     v_act.sa_handler  = xmexit_term;
-#if !defined(__APPLE__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
     v_act.sa_restorer = NULL;
 #endif
     sigemptyset(&v_act.sa_mask);
