--- kicad/project_template.h.orig	2013-04-11 08:10:30.000000000 +0200
+++ kicad/project_template.h	2014-05-02 10:31:54.000000000 +0200
@@ -200,7 +200,7 @@
      * @brief Get a vector list of filenames for the template. The files are the source files,
      * and have not yet been through any renaming
      */
-    vector<wxFileName> GetFileList();
+    std::vector<wxFileName> GetFileList();
 };
 
 #endif
