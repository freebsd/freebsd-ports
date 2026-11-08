--- net/base/sockaddr_util_posix.cc.orig	2025-10-21 20:19:54 UTC
+++ net/base/sockaddr_util_posix.cc
@@ -51,7 +51,8 @@ bool FillUnixAddress(std::string_view socket_path,
     return true;
   }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
+  // XXX ?
   // Convert the path given into abstract socket name. It must start with
   // the '\0' character, skip over it, as it should already be zero. `addr_len`
   // must specify the length of the structure exactly, as potentially the socket
