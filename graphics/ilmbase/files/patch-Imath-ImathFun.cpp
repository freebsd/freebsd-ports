--- Imath/ImathFun.cpp.orig	2013-06-18 21:51:38.000000000 +0200
+++ Imath/ImathFun.cpp	2013-10-04 20:06:42.000000000 +0200
@@ -33,6 +33,7 @@
 ///////////////////////////////////////////////////////////////////////////
 
 
+#include <inttypes.h>
 #include "ImathFun.h"
 
 IMATH_INTERNAL_NAMESPACE_SOURCE_ENTER
@@ -41,14 +42,14 @@
 float
 succf (float f)
 {
-    union {float f; int i;} u;
+    union {float f; int32_t i;} u;
     u.f = f;
 
     if ((u.i & 0x7f800000) == 0x7f800000)
     {
         // Nan or infinity; don't change value.
     }
-    else if (u.i == 0x00000000 || u.i == 0x80000000)
+    else if (u.i == (int32_t)0x00000000 || u.i == (int32_t)0x80000000)
     {
         // Plus or minus zero.
 
@@ -76,14 +77,14 @@
 float
 predf (float f)
 {
-    union {float f; int i;} u;
+    union {float f; int32_t i;} u;
     u.f = f;
 
     if ((u.i & 0x7f800000) == 0x7f800000)
     {
         // Nan or infinity; don't change value.
     }
-    else if (u.i == 0x00000000 || u.i == 0x80000000)
+    else if (u.i == (int32_t)0x00000000 || u.i == (int32_t)0x80000000)
     {
         // Plus or minus zero.
 
