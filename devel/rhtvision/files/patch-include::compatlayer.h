--- include/compatlayer.h.orig	Wed Feb  6 22:35:38 2002
+++ include/compatlayer.h	Fri Jun  7 04:35:14 2002
@@ -117,6 +117,7 @@
 #undef DIRSEPARATOR
 #undef DIRSEPARATOR_
 #undef CLY_ISOCpp98
+#undef CLY_filebuf
 #undef CLY_OpenModeT
 #undef CLY_StreamPosT
 #undef CLY_StreamOffT
@@ -225,13 +226,21 @@
     library. GCC implemented it in version 3.0. BC++ implemented some
     stuff in versions like BC++ 5.5. So that's a real mess. */
  #if __GNUC__>=3
+  // gcc 3.1 needs a special filebuf
+  #if __GNUC_MINOR__<1
+   #define CLY_filebuf       std::filebuf
+   #define CLY_NewFBFromFD(f) new CLY_filebuf(fdopen(f,"rb+"),ios::in|ios::out|ios::binary)
+  #else
+   #undef  CLY_DefineSpecialFileBuf
+   #define CLY_DefineSpecialFileBuf 1
+   #define CLY_NewFBFromFD(f) new CLY_filebuf(f,ios::in|ios::out|ios::binary)
+  #endif
   #define CLY_ISOCpp98 1
   #define CLY_OpenModeT      std::ios::openmode
   #define CLY_StreamPosT     std::streampos
   #define CLY_StreamOffT     std::streamoff
   #define CLY_IOSSeekDir     std::ios::seekdir
   #define CLY_FBOpenProtDef  0
-  #define CLY_NewFBFromFD(f) new filebuf(fdopen(f,"rb+"),ios::in|ios::out|ios::binary)
   #define CLY_PubSetBuf(a,b) pubsetbuf(a,b)
   #define CLY_FBOpen(a,b,c)  open(a,b)
   #define CLY_IOSBin         std::ios::binary
@@ -252,6 +261,7 @@
   #undef  IOSTREAM_HEADER
   #define IOSTREAM_HEADER <iostream>
  #else
+  #define CLY_filebuf        filebuf
   #define CLY_OpenModeT      int
   #define CLY_StreamPosT     streampos
   #define CLY_StreamOffT     streamoff
@@ -830,6 +840,7 @@
   #define Uses_CLY_IfStreamGetLine 1
  #endif
 
+ #define CLY_filebuf        filebuf
  #define CLY_OpenModeT      int
  #define CLY_StreamPosT     streampos
  #define CLY_StreamOffT     streamoff
@@ -1040,6 +1051,7 @@
  #define IfStreamGetLine(istream,buffer,size) \
          istream.getline(buffer,size)
 
+ #define CLY_filebuf        filebuf
  #define CLY_OpenModeT      int
  #define CLY_StreamPosT     streampos
  #define CLY_StreamOffT     streamoff
