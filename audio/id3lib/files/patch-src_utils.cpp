
$FreeBSD$

--- src/utils.cpp.orig	Mon Sep 11 09:46:32 2000
+++ src/utils.cpp	Sun Jul 21 15:13:19 2002
@@ -231,7 +231,7 @@
 
   bool exists(const char *name)
   {
-    ifstream file(name, ios::nocreate);
+    ifstream file(name/*, ios::nocreate*/);
     return file.is_open() != 0;
   }
   
@@ -256,7 +256,7 @@
     size_t size = 0;
     if (file.is_open())
     {
-      streamoff curpos = file.tellp();
+      streampos curpos = file.tellp();
       file.seekp(0, ios::end);
       size = file.tellp();
       file.seekp(curpos);
@@ -275,7 +275,7 @@
     {
       file.close();
     }
-    file.open(name, ios::in | ios::out | ios::binary | ios::nocreate);
+    file.open(name, ios::in | ios::out | ios::binary /*| ios::nocreate*/);
     if (!file)
     {
       return ID3E_ReadOnly;
@@ -290,7 +290,7 @@
     {
       file.close();
     }
-    file.open(name, ios::in | ios::binary | ios::nocreate);
+    file.open(name, ios::in | ios::binary /*| ios::nocreate*/);
     if (!file)
     {
       return ID3E_NoFile;
