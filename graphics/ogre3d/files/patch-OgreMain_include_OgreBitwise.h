--- OgreMain/include/OgreBitwise.h.orig	2021-08-04 18:33:45 UTC
+++ OgreMain/include/OgreBitwise.h
@@ -29,6 +29,9 @@ ------------------------------------------------------
 #define _Bitwise_H__
 
 #include "OgrePrerequisites.h"
+#undef bswap16
+#undef bswap32
+#undef bswap64
 
 #ifdef bswap16
 #undef bswap16
