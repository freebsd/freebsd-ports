--- remoting/host/ipc_constants.cc.orig	2026-04-28 21:06:17 UTC
+++ remoting/host/ipc_constants.cc
@@ -13,7 +13,7 @@
 #include "mojo/public/cpp/platform/named_platform_channel.h"
 #include "remoting/base/username.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #include "remoting/base/file_path_util_linux.h"
 #endif
@@ -46,7 +46,7 @@ constexpr char kAgentProcessBrokerIpcName[] =
 
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if !defined(NDEBUG)
 constexpr char kLoginSessionReporterIpcName[] =
@@ -63,7 +63,7 @@ mojo::NamedPlatformChannel::ServerName GetServerName(s
 #endif
 
 mojo::NamedPlatformChannel::ServerName GetServerName(std::string_view name) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return GetVarLibDir().Append(name).value();
 #else
   return mojo::NamedPlatformChannel::ServerNameFromUTF8(name);
@@ -105,7 +105,7 @@ GetChromotingHostServicesServerName() {
   return *server_name;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const mojo::NamedPlatformChannel::ServerName&
 GetLegacyChromotingHostServicesServerName() {
   static const base::NoDestructor<mojo::NamedPlatformChannel::ServerName>
@@ -137,7 +137,7 @@ GetAgentProcessBrokerServerName() {
 
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 const char kLoginSessionReporterMessagePipeId[] = "login-session-reporter";
 
