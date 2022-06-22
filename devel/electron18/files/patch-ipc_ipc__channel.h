--- ipc/ipc_channel.h.orig	2022-05-19 05:17:44 UTC
+++ ipc/ipc_channel.h
@@ -235,7 +235,7 @@ class COMPONENT_EXPORT(IPC) Channel : public Sender {
   static std::string GenerateUniqueRandomChannelID();
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
