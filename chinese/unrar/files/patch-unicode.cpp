--- unicode.cpp.orig	Sun Aug  1 01:54:23 2004
+++ unicode.cpp	Sun Aug  1 01:54:56 2004
@@ -2,6 +2,7 @@
 
 void WideToChar(const wchar *Src,char *Dest,int DestSize)
 {
+#if 0 /* patch for chinese filename */
 #ifdef _WIN_32
   WideCharToMultiByte(CP_ACP,0,Src,-1,Dest,DestSize,NULL,NULL);
 #else
@@ -18,6 +19,7 @@
     if (Src[I]==0)
       break;
   }
+#endif
 #endif
 #endif
 #endif
