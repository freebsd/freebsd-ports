Description: Fix function signature
Author: Mathieu Malaterre <malat@debian.org>
Origin: upstream, https://jxrlib.codeplex.com/SourceControl/changeset/04cf339385b8196f98025b43a366a0790deac994
Bug-Debian: http://bugs.debian.org/748590

--- image/decode/JXRTranscode.c.orig	2017-10-20 15:09:28 UTC
+++ image/decode/JXRTranscode.c
@@ -47,7 +47,7 @@ EXTERN_C Void FreeCodingContextDec(CWMImageStrCodec *)
 EXTERN_C Int StrEncInit(CWMImageStrCodec *);
 EXTERN_C Void StrIOEncTerm(CWMImageStrCodec *);
 EXTERN_C Void FreeCodingContextEnc(CWMImageStrCodec *);
-EXTERN_C Void encodeMB(CWMImageStrCodec *, Int, Int);
+EXTERN_C Int encodeMB(CWMImageStrCodec *, Int, Int);
 EXTERN_C Int  writeIndexTableNull(CWMImageStrCodec *);
 EXTERN_C Void writePacketHeader(BitIOInfo *, U8, U8);
 
