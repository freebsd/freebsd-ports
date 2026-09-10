--- remoting/host/setup/daemon_controller.h.orig	2026-06-23 23:37:18 UTC
+++ remoting/host/setup/daemon_controller.h
@@ -152,13 +152,13 @@ class DaemonController : public base::RefCountedThread
     // unprivileged.
     virtual bool is_privileged() const = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Returns true if the host has a multi-process architecture.
     virtual bool is_multi_process() const = 0;
 #endif
   };
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Set the host type. If nullptr is passed (the default), the host type will
   // be automatically determined by checking which host type is running. If none
   // is running, HostType::GetDefaultHostType() will be used.
@@ -227,7 +227,7 @@ class DaemonController : public base::RefCountedThread
   // unprivileged.
   bool is_privileged() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns true if the host has a multi-process architecture.
   bool is_multi_process() const;
 #endif
