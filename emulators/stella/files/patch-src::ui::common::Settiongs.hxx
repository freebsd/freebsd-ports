--- src/ui/common/Settings.hxx.orig	Tue Feb 18 10:19:45 2003
+++ src/ui/common/Settings.hxx	Wed Sep 17 00:40:23 2003
@@ -32,7 +32,7 @@
     ~Settings();
 
     bool handleCommandLineArgs(int ac, char* av[]);
-    void handleRCFile(istream& in);
+    void handleRCFile(std::istream& in);
 
   public:
     // Indicates whether to use fullscreen
