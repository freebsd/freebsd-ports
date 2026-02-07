- Add %%PREFIX%%/bin to PATH so that gmake and cmake executables would be found

--- src/cpp/session/modules/SessionGit.cpp.orig	2025-01-31 18:17:58 UTC
+++ src/cpp/session/modules/SessionGit.cpp
@@ -137,6 +137,9 @@ core::system::ProcessOptions procOptions()
    FilePath postbackDir = module_context::rPostbackScriptsDir();
    core::system::addToPath(&childEnv, postbackDir.getAbsolutePath());
 
+   // add $PREFIX/bin to path
+   core::system::addToPath(&childEnv, "%%PREFIX%%/bin");
+
    options.workingDir = projects::projectContext().directory();
 
 #ifdef _WIN32
