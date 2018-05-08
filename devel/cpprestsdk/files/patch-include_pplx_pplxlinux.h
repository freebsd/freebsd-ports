https://github.com/Microsoft/cpprestsdk/issues/747

--- include/pplx/pplxlinux.h.orig	2016-10-28 19:20:12 UTC
+++ include/pplx/pplxlinux.h
@@ -240,6 +240,7 @@ namespace platform
     {
     public:
         _PPLXIMP virtual void schedule( TaskProc_t proc, _In_ void* param);
+        virtual ~linux_scheduler() {}
     };
 
 } // namespace details
