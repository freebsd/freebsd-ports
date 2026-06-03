--- src/unisock.cpp.orig	2026-02-23 10:43:56 UTC
+++ src/unisock.cpp
@@ -9,7 +9,6 @@
 //-------------------------------------------------------------------*--------*
 
 #include "unisock.h"
-#undef BYTE_ORDER
 
 #ifdef VXWORKS
 #include "fastdbShim.h"
