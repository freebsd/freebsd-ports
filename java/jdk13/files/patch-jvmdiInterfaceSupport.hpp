$FreeBSD$

--- ../../hotspot1.3.1/src/share/vm/runtime/jvmdiInterfaceSupport.hpp	11 Jul 2001 21:32:58 -0000	1.1
+++ ../../hotspot1.3.1/src/share/vm/runtime/jvmdiInterfaceSupport.hpp	27 Jul 2003 10:42:07 -0000	1.2
@@ -30,7 +30,7 @@
   result_type JNICALL methodName signature {                                         \
     JavaThread* thread = (JavaThread*) ThreadLocalStorage::thread();                 \
     TransitionClass __tiv(thread);                                                   \
-    __ENTRY(result_type, methodName##signature, thread)                              \
+    __ENTRY(result_type, methodName signature, thread)                              \
     debug_only(VMNativeEntryWrapper __vew;)                                          \
     debug_only(const char* const _jvmdi_methodName_ = #methodName;)                  \
     debug_only(bool  _trace_ = trace; );                                             \
