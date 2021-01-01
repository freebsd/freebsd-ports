--- content/public/common/child_process_host.h.orig	2019-09-10 11:14:02 UTC
+++ content/public/common/child_process_host.h
@@ -51,7 +51,7 @@ class CONTENT_EXPORT ChildProcessHost : public IPC::Se
     // No special behavior requested.
     CHILD_NORMAL = 0,
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Indicates that the child execed after forking may be execced from
     // /proc/self/exe rather than using the "real" app path. This prevents
     // autoupdate from confusing us if it changes the file out from under us.
