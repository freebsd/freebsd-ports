--- ./rts/lib/gml/gmlcls.h.orig	2010-09-06 16:16:18.000000000 +0400
+++ ./rts/lib/gml/gmlcls.h	2010-09-15 23:36:35.000000000 +0400
@@ -60,7 +60,7 @@
 //#define BOOST_AC_USE_PTHREADS
 
 // memory barriers for different platforms
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__)
 #	include <libkern/OSAtomic.h>
 #	define GML_MEMBAR OSMemoryBarrier()
 #elif defined(__GNUC__)
@@ -112,7 +112,7 @@
 #	define GML_TYPENAME
 #endif
 
-#ifndef _WIN32 //defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__)
 #	define GML_USE_SPEEDY_TLS 1
 #	include "System/Platform/errorhandler.h"
 #	include "speedy-tls.h"
