--- fdbserver/fdbserver.actor.cpp.orig	2019-04-09 00:11:05 UTC
+++ fdbserver/fdbserver.actor.cpp
@@ -60,7 +60,7 @@
 #include "versions.h"
 #endif
 
-#ifdef  __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <execinfo.h>
 #include <signal.h>
 #ifdef ALLOC_INSTRUMENTATION
@@ -288,7 +288,7 @@ class WorldReadablePermissions { (public)
 			throw platform_error();
 		}
 		permission.set_permissions( &sa );
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 		// There is nothing to do here, since the default permissions are fine
 #else
 		#error Port me!
@@ -298,7 +298,7 @@ class WorldReadablePermissions { (public)
 	virtual ~WorldReadablePermissions() {
 #ifdef _WIN32
 		LocalFree( sa.lpSecurityDescriptor );
-#elif (defined(__linux__) || defined(__APPLE__))
+#elif (defined(__linux__) || defined(__APPLE__)) || defined(__FreeBSD__)
 		// There is nothing to do here, since the default permissions are fine
 #else
 		#error Port me!
