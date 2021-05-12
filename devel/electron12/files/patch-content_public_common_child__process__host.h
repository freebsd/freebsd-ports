--- content/public/common/child_process_host.h.orig	2021-01-07 00:36:33 UTC
+++ content/public/common/child_process_host.h
@@ -81,7 +81,7 @@ class CONTENT_EXPORT ChildProcessHost : public IPC::Se
     // No special behavior requested.
     CHILD_NORMAL = 0,
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // Indicates that the child execed after forking may be execced from
     // /proc/self/exe rather than using the "real" app path. This prevents
     // autoupdate from confusing us if it changes the file out from under us.
