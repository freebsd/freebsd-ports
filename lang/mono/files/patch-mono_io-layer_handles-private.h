--- mono/io-layer/handles-private.h.orig	2015-06-17 16:52:15 UTC
+++ mono/io-layer/handles-private.h
@@ -22,7 +22,7 @@
 #include <mono/io-layer/shared.h>
 #include <mono/utils/atomic.h>
 
-#define _WAPI_PRIVATE_MAX_SLOTS		(1024 * 16)
+#define _WAPI_PRIVATE_MAX_SLOTS		(1024 * 17)
 #define _WAPI_PRIVATE_HANDLES(x) (_wapi_private_handles [x / _WAPI_HANDLE_INITIAL_COUNT][x % _WAPI_HANDLE_INITIAL_COUNT])
 #define _WAPI_PRIVATE_HAVE_SLOT(x) ((GPOINTER_TO_UINT (x) / _WAPI_PRIVATE_MAX_SLOTS) < _WAPI_PRIVATE_MAX_SLOTS && \
 					_wapi_private_handles [GPOINTER_TO_UINT (x) / _WAPI_HANDLE_INITIAL_COUNT] != NULL)
