Index: src/osgPlugins/osc/osc/OscHostEndianness.h
===================================================================
--- src/osgPlugins/osc/osc/OscHostEndianness.h	(revision 13802)
+++ src/osgPlugins/osc/osc/OscHostEndianness.h	(working copy)
@@ -60,6 +60,15 @@
         #else
             #error Unknown machine endianness detected.
         #endif
+    #elif defined(__FreeBSD__)
+        #include <sys/endian.h>
+        #if (_BYTE_ORDER == _LITTLE_ENDIAN)
+            #define __LITTLE_ENDIAN__
+        #elif (_BYTE_ORDER == _BIG_ENDIAN)
+            #define __BIG_ENDIAN__
+        #else
+            #error Unknown machine endianness detected.
+        #endif
     #endif
 
     #if   defined(__LITTLE_ENDIAN__)
@@ -74,7 +83,7 @@
 
     #else
 
-        #error please edit OSCHostEndianness.h to configure endianness
+        #error please edit OscHostEndianness.h to configure endianness
 
     #endif
 
