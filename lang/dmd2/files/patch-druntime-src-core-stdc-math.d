--- ../druntime/src/core/stdc/math.d.orig	2010-11-30 13:56:26.000000000 +0000
+++ ../druntime/src/core/stdc/math.d	2010-11-30 13:56:50.000000000 +0000
@@ -479,7 +479,7 @@
 //       but we can approximate.
 version( FreeBSD )
 {
-  version (all) // < 8-CURRENT
+  version (none) // < 8-CURRENT
   {
     real    acosl(real x) { return acos(x); }
     real    asinl(real x) { return asin(x); }
