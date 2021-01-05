--- libs/wxcurl/include/wx/curl/thread.h.orig	2020-10-22 23:20:06 UTC
+++ libs/wxcurl/include/wx/curl/thread.h
@@ -43,7 +43,7 @@ enum wxCurlThreadError
 };
 
 //! The stack size for wxCurl threads.
-#define wxCURL_THREAD_STACK_SIZE            2048
+#define wxCURL_THREAD_STACK_SIZE            1024
 
 
 // ----------------------------------------------------------------------------
