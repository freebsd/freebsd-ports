--- util/Serialize.cpp.orig	2009-04-13 08:56:38.000000000 +0200
+++ util/Serialize.cpp	2009-04-13 08:56:56.000000000 +0200
@@ -65,7 +65,7 @@
 // some endianness and size checks to ensure portability of binary save files; of one or more of these fails, it means
 // that FreeOrion is not supported on your platform/compiler pair, and must be modified to provide data of the
 // appropriate size(s).
-#ifndef BOOST_LITTLE_ENDIAN
+#if (_BYTE_ORDER != _LITTLE_ENDIAN)
 #  error "Incompatible endianness for binary serialization."
 #endif
 BOOST_STATIC_ASSERT(sizeof(char) == 1);
