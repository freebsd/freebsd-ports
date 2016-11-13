--- vcl/unx/gtk/gtkinst.cxx.orig	2016-11-13 15:24:04 UTC
+++ vcl/unx/gtk/gtkinst.cxx
@@ -298,28 +298,29 @@ SalPrinter* GtkInstance::CreatePrinter( 
  * for each pair, so we can accurately restore
  * it later.
  */
-thread_local std::stack<sal_uIntPtr> GtkYieldMutex::yieldCounts;
 
 void GtkYieldMutex::ThreadsEnter()
 {
     acquire();
-    if (!yieldCounts.empty()) {
-        auto n = yieldCounts.top();
-        yieldCounts.pop();
-        for (; n != 0; --n) {
+    if( !aYieldStack.empty() )
+    { /* Previously called ThreadsLeave() */
+        sal_uLong nCount = aYieldStack.front();
+        aYieldStack.pop_front();
+        while( nCount-- > 1 )
             acquire();
-        }
     }
 }
 
 void GtkYieldMutex::ThreadsLeave()
 {
+    aYieldStack.push_front( mnCount );
     assert(mnCount != 0);
-    auto n = mnCount - 1;
-    yieldCounts.push(n);
-    for (sal_uIntPtr i = 0; i != n + 1; ++i) {
+    SAL_WARN_IF(
+        mnThreadId && mnThreadId != osl::Thread::getCurrentIdentifier(),
+        "vcl.gtk", "other thread " << mnThreadId << " owns the mutex");
+    while( mnCount > 1 )
         release();
-    }
+    release();
 }
 
 SalVirtualDevice* GtkInstance::CreateVirtualDevice( SalGraphics *pG,
