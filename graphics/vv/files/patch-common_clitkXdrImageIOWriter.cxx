Remove register storage class specifier.

C++17 removed the 'register' keyword which was deprecated in C++11.

--- common/clitkXdrImageIOWriter.cxx.orig	2025-04-17 12:54:38 UTC
+++ common/clitkXdrImageIOWriter.cxx
@@ -464,7 +464,7 @@ static size_t nki_private_compress(signed char  *dest,
   unsigned long		iCRC;
   unsigned long		iCRC2;
   unsigned int          iHeaderSize=8;                      // value for iMode==1 and iMode==3
-  register int		val;
+  int		val;
   size_t                i,j;
   NKI_MODE2*		pHeader = (NKI_MODE2*)dest;
   NKI_MODE2_64BITS*     pHeader_64bits = (NKI_MODE2_64BITS*)dest;
