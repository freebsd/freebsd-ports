--- hiptext.cc.orig	2016-06-21 21:09:17 UTC
+++ hiptext.cc
@@ -197,9 +197,9 @@ inline string GetExtension(const string&
 int main(int argc, char** argv) {
   // if (!isatty(1))
   //   FLAGS_color = false;
-  google::SetUsageMessage("hiptext [FLAGS]");
-  google::SetVersionString("0.1");
-  google::ParseCommandLineFlags(&argc, &argv, true);
+  gflags::SetUsageMessage("hiptext [FLAGS]");
+  gflags::SetVersionString("0.1");
+  gflags::ParseCommandLineFlags(&argc, &argv, true);
   google::InitGoogleLogging(argv[0]);
   google::InstallFailureSignalHandler();
   const char* lang = std::getenv("LANG");
