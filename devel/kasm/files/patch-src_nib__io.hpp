--- src/nib_io.hpp.orig	Thu Feb  8 19:31:17 2001
+++ src/nib_io.hpp	Mon Aug 28 08:03:41 2006
@@ -29,6 +29,7 @@
 #define __NIB_IO_H
 
 #include <fstream>
+using namespace std;
 
 
 /*********************************
@@ -49,9 +50,8 @@
   // Constructors
   nibfstream(): fstream() { ibuff = obuff = false; }
 #ifndef MSDOS
-  nibfstream(int fd)  : fstream(fd) { ibuff = obuff = false; }
-  nibfstream(const char *name, int mode = ios::in, int prot = 0644)
-    : fstream(name, mode, prot) { ibuff = obuff = false; }
+  nibfstream(const char *name, ios_base::openmode mode = ios::in, int prot = 0644)
+    : fstream(name, mode) { ibuff = obuff = false; }
 #else
   nibfstream(const char *name, int mode = ios::in)
     : fstream(name, mode) { ibuff = obuff = false; } 
@@ -59,8 +59,8 @@
   ~nibfstream() { close(); }
 
 #ifndef MSDOS
-  void open(const char *name, int mode, int prot = 0664)
-    { fstream::open(name, mode, prot); ibuff = obuff = false; }
+  void open(const char *name, ios_base::openmode mode, int prot = 0664)
+    { fstream::open(name, mode); ibuff = obuff = false; }
 #else
   void open(const char *name, int mode)
     { fstream::open(name, mode); ibuff = obuff = false; }  
