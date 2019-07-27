--- OgreMain/include/OgreBitwise.h.orig	2019-03-30 05:11:05 UTC
+++ OgreMain/include/OgreBitwise.h
@@ -29,6 +29,9 @@ THE SOFTWARE.
 #define _Bitwise_H__
 
 #include "OgrePrerequisites.h"
+#undef bswap16
+#undef bswap32
+#undef bswap64
 
 #ifndef __has_builtin
     // Compatibility with non-clang compilers
