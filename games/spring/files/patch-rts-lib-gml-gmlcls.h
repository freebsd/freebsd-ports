--- rts/lib/gml/gmlcls.h.orig	2013-12-07 00:06:39.928020847 +0400
+++ rts/lib/gml/gmlcls.h	2013-12-07 00:09:21.477010398 +0400
@@ -43,7 +43,7 @@
 extern bool ThreadRegistered();
 
 // memory barriers for different platforms
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__APPLE__)
 #	include <libkern/OSAtomic.h>
 #	define GML_MEMBAR OSMemoryBarrier()
 #elif defined(__GNUC__)
@@ -95,7 +95,7 @@
 #	define GML_TYPENAME
 #endif
 
-#ifndef _WIN32 //defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__APPLE__)
 #	define GML_USE_SPEEDY_TLS 1
 #	include "System/Platform/errorhandler.h"
 #	include "speedy-tls.h"
@@ -234,11 +234,7 @@
 	}
 	virtual ~gmlBaseMutexLock() {
 		if (GML::Enabled()) {
-#if (BOOST_VERSION >= 103500)
-			((T*)lockdata)->boost::unique_lock<U>::~unique_lock();
-#else
-			((T*)lockdata)->boost::scoped_lock<U>::~scoped_lock();
-#endif
+			((T*)lockdata)->~T();
 		}
 	}
 };
