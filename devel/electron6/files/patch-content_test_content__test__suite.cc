--- content/test/content_test_suite.cc.orig	2019-09-10 10:42:37 UTC
+++ content/test/content_test_suite.cc
@@ -81,6 +81,7 @@ void ContentTestSuite::Initialize() {
   // to initialize GL, so don't do it here.
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   bool is_child_process = command_line->HasSwitch(switches::kTestChildProcess);
+#if !defined(OS_BSD)
   if (!is_child_process) {
     gl::GLSurfaceTestSupport::InitializeNoExtensionsOneOff();
     auto* gpu_feature_info = gpu::GetTestGpuThreadHolder()->GetGpuFeatureInfo();
@@ -88,6 +89,7 @@ void ContentTestSuite::Initialize() {
         gpu_feature_info->disabled_extensions);
     gl::init::InitializeExtensionSettingsOneOffPlatform();
   }
+#endif
   testing::TestEventListeners& listeners =
       testing::UnitTest::GetInstance()->listeners();
   listeners.Append(new TestInitializationListener);
