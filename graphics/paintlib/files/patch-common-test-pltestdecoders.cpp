--- common/test/pltestdecoders.cpp.orig	Fri Jun 18 22:09:17 2004
+++ common/test/pltestdecoders.cpp	Fri Jun 18 22:09:36 2004
@@ -135,7 +135,7 @@
 
 #ifndef WIN32
 // this function is used to select all files that do not start with a dot
-int selectFile(const struct dirent * theEntry)
+int selectFile(struct dirent * theEntry)
 {
   if (theEntry->d_name[0] == '.')
   {
