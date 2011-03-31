--- zpsfx.cpp.orig	2011-03-30 19:27:34.000000000 -0400
+++ zpsfx.cpp	2011-03-30 19:28:24.000000000 -0400
@@ -15,19 +15,38 @@
 the executable smaller. -DNDEBUG turns off run time checks.
 To convert a ZPAQ archive to a self extracting archive:
 
+On Windows:
+
   copy/b zpsfx.exe+zpsfx.tag+archive.zpaq archive.exe
 
+On FreeBSD(the choice of archive name is discretionary): 
+
+  cat zpsfx zpsfx.tag archive.zpaq > archive.sfx
+
 zpsfx.tag is a 13 byte file used to mark the start of the compressed data
 that is appended. Alternatively, zpaq with the "t" modifier will append
 the same tag ("a" appends).
 
+On Windows:
+
   copy zpsfx.exe archive.exe
   zpaq ta archive.exe files...
 
+On FreeBSD:
+
+  cp zpsfx archive.sfx
+  zpaq ta archive.sfx files...
+
 To extract:
 
+On Windows:
+
   archive.exe
 
+On FreeBSD:
+
+  archive.sfx
+
 The program reads itself and decompresses the appended archive.
 You must enter the .exe extension as shown. If the file is not in
 the current folder then you need to specify the path. The PATH environment
