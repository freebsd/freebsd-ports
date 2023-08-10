--- tools/external/driver-tool/sratools.cpp.orig	2023-07-10 16:23:35 UTC
+++ tools/external/driver-tool/sratools.cpp
@@ -420,6 +420,7 @@ static int main(CommandLine const &argv)
     enableLogging(argv.toolName.c_str());
 #endif
     LOG(7) << "executable path: " << (std::string)argv.fullPathToExe << std::endl;
+    // std::cerr << "executable path: " << (std::string)argv.fullPathToExe << std::endl;
 
     config = new Config();
     struct Defer { ~Defer() { delete config; config = nullptr; } } freeConfig;
@@ -576,6 +577,14 @@ static int main(CommandLine const &argv)
 }
 
 } // namespace sratools
+
+#if BSD
+int main(int argc, char *argv[], char *envp[])
+{
+    auto const invocation = CommandLine(argc, argv, envp, nullptr);
+    return sratools::main(invocation);
+}
+#endif
 
 #if MAC
 int main(int argc, char *argv[], char *envp[], char *apple[])
