--- content/renderer/render_thread_impl.cc.orig	2021-01-25 11:26:59 UTC
+++ content/renderer/render_thread_impl.cc
@@ -173,7 +173,7 @@
 
 #if defined(OS_MAC)
 #include <malloc/malloc.h>
-#else
+#elif !defined(OS_BSD)
 #include <malloc.h>
 #endif
 
