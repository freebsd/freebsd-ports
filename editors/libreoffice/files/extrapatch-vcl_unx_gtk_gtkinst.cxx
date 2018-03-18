--- vcl/unx/gtk/gtkinst.cxx.orig	2018-02-22 17:45:41 UTC
+++ vcl/unx/gtk/gtkinst.cxx
@@ -302,28 +302,29 @@ SalPrinter* GtkInstance::CreatePrinter( 
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
+    aYieldStack.push_front( m_nCount );
     assert(m_nCount != 0);
-    auto n = m_nCount - 1;
-    yieldCounts.push(n);
-    for (sal_uIntPtr i = 0; i != n + 1; ++i) {
+    SAL_WARN_IF(
+        m_nThreadId && m_nThreadId != osl::Thread::getCurrentIdentifier(),
+        "vcl.gtk", "other thread " << m_nThreadId << " owns the mutex");
+    while( m_nCount > 1 )
         release();
-    }
+    release();
 }
 
 SalVirtualDevice* GtkInstance::CreateVirtualDevice( SalGraphics *pG,
