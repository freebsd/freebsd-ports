--- Source/NetworkIDObject.cpp.orig	2009-03-26 07:09:10.802327111 +0000
+++ Source/NetworkIDObject.cpp	2009-03-26 07:10:01.202313701 +0000
@@ -18,7 +18,7 @@
 #include "NetworkIDManager.h"
 #include "RakAssert.h"
 
-#if !defined (_WIN32) && !defined (_XBOX) && !defined(X360)
+#if !defined (_WIN32) && !defined (_XBOX) && !defined(X360) && !defined(__FreeBSD__)
 #include <alloca.h>
 #endif
 
