--- remoting/base/username.h.orig	2026-08-24 20:59:34 UTC
+++ remoting/base/username.h
@@ -16,7 +16,7 @@ std::string GetUsername();
 // error or if not implemented.
 std::string GetUsername();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the username that the network process is run as.
 base::cstring_view GetNetworkProcessUsername();
 
