--- unicode.cpp.orig	Thu Aug  4 00:34:30 2005
+++ unicode.cpp	Wed Sep  7 22:01:58 2005
@@ -7,6 +7,7 @@
 bool WideToChar(const wchar *Src,char *Dest,int DestSize)
 {
   bool RetCode=true;
+  return(RetCode); /* patch for chinese filename */
 #ifdef _WIN_32
   if (WideCharToMultiByte(CP_ACP,0,Src,-1,Dest,DestSize,NULL,NULL)==0)
     RetCode=false;
