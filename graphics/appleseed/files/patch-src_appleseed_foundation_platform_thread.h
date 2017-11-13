--- src/appleseed/foundation/platform/thread.h.orig	2016-12-15 14:57:39 UTC
+++ src/appleseed/foundation/platform/thread.h
@@ -296,9 +296,8 @@ class APPLESEED_DLLSYMBOL ThreadFlag
 
 inline Spinlock::Spinlock()
 {
-    // todo: is there a simpler way to initialize m_sp in a platform-independent manner?
     boost::detail::spinlock initialized_sp = BOOST_DETAIL_SPINLOCK_INIT;
-    m_sp = initialized_sp;
+    std::memcpy(&m_sp, &initialized_sp, sizeof(initialized_sp));
 }
 
 inline bool Spinlock::try_lock()
