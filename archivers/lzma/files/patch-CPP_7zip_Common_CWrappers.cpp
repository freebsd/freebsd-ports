--- CPP/7zip/Common/CWrappers.cpp.orig	2010-04-28 22:07:56.000000000 -0400
+++ CPP/7zip/Common/CWrappers.cpp	2010-04-28 22:26:55.000000000 -0400
@@ -164,13 +164,15 @@
   return 0;
 }
 
-extern "C" static Byte Wrap_ReadByte(void *pp)
+extern "C" {
+static Byte Wrap_ReadByte(void *pp)
 {
   CByteInBufWrap *p = (CByteInBufWrap *)pp;
   if (p->Cur != p->Lim)
     return *p->Cur++;
   return p->ReadByteFromNewBlock();
 }
+}
 
 CByteInBufWrap::CByteInBufWrap(): Buf(0)
 {
@@ -210,7 +212,8 @@
   return Res;
 }
 
-extern "C" static void Wrap_WriteByte(void *pp, Byte b)
+extern "C" {
+static void Wrap_WriteByte(void *pp, Byte b)
 {
   CByteOutBufWrap *p = (CByteOutBufWrap *)pp;
   Byte *dest = p->Cur;
@@ -219,6 +222,7 @@
   if (dest == p->Lim)
     p->Flush();
 }
+}
 
 CByteOutBufWrap::CByteOutBufWrap(): Buf(0)
 {
