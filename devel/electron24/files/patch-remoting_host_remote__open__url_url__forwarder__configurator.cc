--- remoting/host/remote_open_url/url_forwarder_configurator.cc.orig	2022-02-28 16:54:41 UTC
+++ remoting/host/remote_open_url/url_forwarder_configurator.cc
@@ -12,7 +12,7 @@ UrlForwarderConfigurator::UrlForwarderConfigurator() =
 
 UrlForwarderConfigurator::~UrlForwarderConfigurator() = default;
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
 
 // static
 std::unique_ptr<UrlForwarderConfigurator> UrlForwarderConfigurator::Create() {
