--- rts/System/Threading/SpringThreading.h.orig	2020-12-26 12:45:43 UTC
+++ rts/System/Threading/SpringThreading.h
@@ -13,7 +13,7 @@
 
 #if   defined(_WIN32)
 	#include "System/Platform/Win/CriticalSection.h"
-#elif defined(__APPLE__) || !defined(USE_FUTEX)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || !defined(USE_FUTEX)
 	#include "System/Platform/Mac/Signal.h"
 #elif !defined(__APPLE__) && defined(USE_FUTEX)
 	#include "System/Platform/Linux/Futex.h"
@@ -37,7 +37,7 @@ namespace spring {
 	typedef CriticalSection recursive_mutex;
 	typedef win_signal signal;
 	typedef std::condition_variable_any condition_variable;
-#elif defined(__APPLE__) || !defined(USE_FUTEX)
+#elif defined(__APPLE__) || defined(__FreeBSD__) || !defined(USE_FUTEX)
 	typedef std::mutex mutex;
 	typedef std::recursive_mutex recursive_mutex;
 	typedef mac_signal signal;
