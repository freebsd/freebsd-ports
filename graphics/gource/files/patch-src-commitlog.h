--- src/commitlog.h.orig	2009-11-25 05:29:14.000000000 +0300
+++ src/commitlog.h	2009-11-26 15:06:52.000000000 +0300
@@ -42,7 +42,7 @@ public:
 class RCommit {
     vec3f fileColour(std::string filename);
 public:
-    long timestamp;
+    time_t timestamp;
     std::string username;
 
     std::list<RCommitFile> files;
