Big-endian fix from os-string 2.0.2.2.

--- _cabal_deps/os-string-2.0.2/System/OsString/Data/ByteString/Short/Internal.hs.orig	2001-09-09 01:46:40 UTC
+++ _cabal_deps/os-string-2.0.2/System/OsString/Data/ByteString/Short/Internal.hs
@@ -311,7 +311,11 @@
 word16ToLE#, word16FromLE# :: Word# -> Word#
 #endif
 #ifdef WORDS_BIGENDIAN
+#if MIN_VERSION_base(4,16,0)
+word16ToLE# w = wordToWord16# (byteSwap16# (word16ToWord# w))
+#else
 word16ToLE# = byteSwap16#
+#endif
 #else
 word16ToLE# w# = w#
 #endif
