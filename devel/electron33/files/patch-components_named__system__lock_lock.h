--- components/named_system_lock/lock.h.orig	2024-08-14 20:54:49 UTC
+++ components/named_system_lock/lock.h
@@ -38,7 +38,7 @@ class ScopedLock {
   // may acquire that lock. The lock name has different meanings per platform:
   // Linux: A shared memory object name starting with `/`. E.g. `/MyApp.lock`.
   // Mac: A bootstrap service name (see `man bootstrap_check_in`).
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   static std::unique_ptr<ScopedLock> Create(const std::string& name,
                                             base::TimeDelta timeout);
 #elif BUILDFLAG(IS_WIN)
