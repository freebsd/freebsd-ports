--- electron/atom/common/node_bindings.cc.orig	2019-11-05 00:13:02 UTC
+++ electron/atom/common/node_bindings.cc
@@ -210,7 +210,7 @@ void NodeBindings::Initialize() {
   node::g_standalone_mode = browser_env_ == BROWSER;
   node::g_upstream_node_mode = false;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Get real command line in renderer process forked by zygote.
   if (browser_env_ != BROWSER)
     AtomCommandLine::InitializeFromCommandLine();
