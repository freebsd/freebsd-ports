--- 3rdParty/StormLib/src/StormPort.h.orig	2019-10-11 11:58:58 UTC
+++ 3rdParty/StormLib/src/StormPort.h
@@ -165,6 +165,7 @@
   #include <ctype.h>
   #include <assert.h>
   #include <errno.h>
+  #include <strings.h>
 
   #ifndef __BIG_ENDIAN__
     #define PLATFORM_LITTLE_ENDIAN
