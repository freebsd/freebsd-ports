- add path %%PREFIX%%/bin to PATH so that gmake and cmake executable would be found

--- src/cpp/session/modules/SessionGit.cpp.orig	2023-08-29 01:47:30 UTC
+++ src/cpp/session/modules/SessionGit.cpp
@@ -130,6 +130,9 @@ core::system::ProcessOptions procOptions()
    FilePath postbackDir = session::options().rpostbackPath().getParent();
    core::system::addToPath(&childEnv, postbackDir.getAbsolutePath());
 
+   // add $PREFIX/bin to path
+   core::system::addToPath(&childEnv, "%%PREFIX%%/bin");
+
    options.workingDir = projects::projectContext().directory();
 
 #ifdef _WIN32
@@ -3370,6 +3373,9 @@ core::Error initialize()
    }
 
    core::system::addToPath(postbackDir.getAbsolutePath());
+
+   // add $PREFIX/bin to path
+   core::system::addToPath("%%PREFIX%%/bin");
 
    // add suspend/resume handler
    addSuspendHandler(SuspendHandler(boost::bind(onSuspend, _2), onResume));
