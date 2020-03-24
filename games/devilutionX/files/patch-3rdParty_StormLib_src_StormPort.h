--- 3rdParty/StormLib/src/StormPort.h.orig	2020-03-10 14:00:26 UTC
+++ 3rdParty/StormLib/src/StormPort.h
@@ -165,6 +165,7 @@
   #include <ctype.h>
   #include <assert.h>
   #include <errno.h>
+  #include <strings.h>
 
   #ifndef __BIG_ENDIAN__
     #define PLATFORM_LITTLE_ENDIAN
@@ -193,6 +194,7 @@
   #include <ctype.h>
   #include <assert.h>
   #include <errno.h>
+  #include <strings.h>
 
   #ifndef __BIG_ENDIAN__
     #define PLATFORM_LITTLE_ENDIAN
