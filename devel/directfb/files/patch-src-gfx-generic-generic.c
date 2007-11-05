--- src/gfx/generic/generic.c.orig	2007-11-02 12:36:17.000000000 +0100
+++ src/gfx/generic/generic.c	2007-11-02 12:40:03.000000000 +0100
@@ -555,7 +555,8 @@
      __u16 *S = (__u16*)Bop;
 
      if (((long)D)&2) {
-        *(((__u16*)D)++) = *S;
+        D = (__u16*)D++;
+        *D = *S;
         i += SperD;
         w--;
      }
