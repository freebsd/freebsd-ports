--- include/pplx/pplxlinux.h.orig	2018-02-22 13:13:56 UTC
+++ include/pplx/pplxlinux.h
@@ -231,14 +231,18 @@ namespace platform
         volatile long _M_owner;
         long _M_recursionCount;
     };
-
 #if defined(__APPLE__)
     class apple_scheduler : public pplx::scheduler_interface
+    {
+    public:
+        virtual ~apple_scheduler(){}
 #else
     class linux_scheduler : public pplx::scheduler_interface
-#endif
     {
     public:
+        virtual ~linux_scheduler(){}
+#endif
+
         _PPLXIMP virtual void schedule( TaskProc_t proc, _In_ void* param);
     };
 
