--- unicode.cpp.orig	Wed Sep  8 21:57:20 2004
+++ unicode.cpp	Tue Oct 26 01:49:46 2004
@@ -6,6 +6,7 @@
 
 void WideToChar(const wchar *Src,char *Dest,int DestSize)
 {
+  return; /* patch for chinese filename */
 #ifdef _WIN_32
   WideCharToMultiByte(CP_ACP,0,Src,-1,Dest,DestSize,NULL,NULL);
 #else
