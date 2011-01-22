--- unicode.cpp.orig	2011-01-04 20:28:47.000000000 +0800
+++ unicode.cpp	2011-01-21 23:01:09.000000000 +0800
@@ -7,6 +7,7 @@
 bool WideToChar(const wchar *Src,char *Dest,size_t DestSize)
 {
   bool RetCode=true;
+  return(RetCode); /* patch for chinese filename */
   *Dest=0; // Set 'Dest' to zero just in case the conversion will fail.
 
 #ifdef _WIN_ALL
