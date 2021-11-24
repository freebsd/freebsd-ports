--- base/process/process_linux.cc.orig	2021-07-15 19:13:29 UTC
+++ base/process/process_linux.cc
@@ -24,7 +24,9 @@ namespace base {
 
 namespace {
 
+#if !defined(OS_BSD)
 const int kForegroundPriority = 0;
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
 // We are more aggressive in our lowering of background process priority
@@ -69,7 +71,7 @@ struct CGroups {
     return groups;
   }
 };
-#else
+#elif !defined(OS_BSD)
 const int kBackgroundPriority = 5;
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
@@ -85,13 +87,18 @@ Time Process::CreationTime() const {
   if (!start_ticks)
     return Time();
 
+#if defined(OS_BSD)
+  return Time::FromTimeT(start_ticks);
+#else
   TimeDelta start_offset = internal::ClockTicksToTimeDelta(start_ticks);
   Time boot_time = internal::GetBootTime();
   if (boot_time.is_null())
     return Time();
   return Time(boot_time + start_offset);
+#endif
 }
 
+#if !defined(OS_BSD)
 // static
 bool Process::CanBackgroundProcesses() {
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
@@ -143,6 +150,7 @@ bool Process::SetProcessBackgrounded(bool background) 
   DPCHECK(result == 0);
   return result == 0;
 }
+#endif // !defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
 bool IsProcessBackgroundedCGroup(const StringPiece& cgroup_contents) {
