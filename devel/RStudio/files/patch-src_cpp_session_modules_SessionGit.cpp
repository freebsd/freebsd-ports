- add path %%PREFIX%%/bin to PATH so that gmake and cmake executable would be found

--- src/cpp/session/modules/SessionGit.cpp.orig	2024-06-04 21:19:10 UTC
+++ src/cpp/session/modules/SessionGit.cpp
@@ -137,6 +137,12 @@ core::system::ProcessOptions procOptions()
    FilePath postbackDir = module_context::rPostbackScriptsDir();
    core::system::addToPath(&childEnv, postbackDir.getAbsolutePath());
 
+   // add $PREFIX/bin to path
+   core::system::addToPath("%%PREFIX%%/bin");
+
+   // add $PREFIX/bin to path
+   core::system::addToPath(&childEnv, "%%PREFIX%%/bin");
+
    options.workingDir = projects::projectContext().directory();
 
 #ifdef _WIN32
