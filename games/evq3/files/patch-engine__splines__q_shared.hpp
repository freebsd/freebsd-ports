--- ./engine/splines/q_shared.hpp.orig	Thu Feb 22 18:28:58 2007
+++ ./engine/splines/q_shared.hpp	Mon Apr 16 23:59:30 2007
@@ -189,7 +189,7 @@
 
 // the mac compiler can't handle >32k of locals, so we
 // just waste space and make big arrays static...
-#ifdef __linux__
+#ifdef __unix__
 
 // bk001205 - from Makefile
 #define stricmp strcasecmp
