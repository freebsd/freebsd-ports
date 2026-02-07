--- test/testfilelister.cpp.orig	2024-02-16 08:46:10 UTC
+++ test/testfilelister.cpp
@@ -43,7 +43,7 @@ class TestFileLister : public TestFixture { (private)
 
     // TODO: generate file list instead
     static std::string findBaseDir() {
-        std::string basedir;
+        std::string basedir = "%%WRKSRC%%/";
         while (!Path::isDirectory(Path::join(basedir, ".github"))) {
             const std::string abspath = Path::getAbsoluteFilePath(basedir);
             basedir += "../";
