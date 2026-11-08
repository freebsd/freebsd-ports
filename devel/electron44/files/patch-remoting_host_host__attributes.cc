--- remoting/host/host_attributes.cc.orig	2026-04-28 21:06:17 UTC
+++ remoting/host/host_attributes.cc
@@ -18,7 +18,7 @@
 #include "remoting/host/win/evaluate_d3d.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/username.h"
 #endif
 
@@ -70,7 +70,7 @@ bool IsMultiProcessHost() {
 bool IsMultiProcessHost() {
 #if BUILDFLAG(IS_WIN)
   return true;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The Linux host is multi-process only when GetHostAttributes() is called in
   // the network process, which is run as the CRD network user.
   return GetUsername() == GetNetworkProcessUsername();
