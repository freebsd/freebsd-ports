--- ipc/ipc_channel.h.orig	2025-08-26 20:49:50 UTC
+++ ipc/ipc_channel.h
@@ -199,7 +199,7 @@ class COMPONENT_EXPORT(IPC) Channel : public Sender {
   // Generates a channel ID that's non-predictable and unique.
   static std::string GenerateUniqueRandomChannelID();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
