--- main.cpp.orig	Sat Oct 25 04:35:20 2003
+++ main.cpp	Tue Mar  2 23:36:04 2004
@@ -278,7 +278,7 @@
    // Determine the name/location of our "home" document
 
    char *s = Persist::getApplicationDirectory(
-      argv[0], "index.html", "doc", FALSE
+      argv[0], "index.html", "../share/doc/fractorama", FALSE
    );
 
    QFileInfo info(s);
