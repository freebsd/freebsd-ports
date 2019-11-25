--- ipc/ipc_channel.h.orig	2019-09-10 11:14:07 UTC
+++ ipc/ipc_channel.h
@@ -245,7 +245,7 @@ class COMPONENT_EXPORT(IPC) Channel : public Sender {
   static std::string GenerateUniqueRandomChannelID();
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Sandboxed processes live in a PID namespace, so when sending the IPC hello
   // message from client to server we need to send the PID from the global
   // PID namespace.
