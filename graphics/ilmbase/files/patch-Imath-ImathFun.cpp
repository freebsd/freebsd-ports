--- Imath/ImathFun.cpp.orig	2006-12-09 06:59:37.000000000 +0900
+++ Imath/ImathFun.cpp	2007-10-07 23:23:38.000000000 +0900
@@ -33,6 +33,7 @@
 ///////////////////////////////////////////////////////////////////////////
 
 
+#include <inttypes.h>
 #include "ImathFun.h"
 
 namespace Imath {
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
 
