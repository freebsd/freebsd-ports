Fix build on 64-bit big-endian machines.

The jsuword type does not exist (which causes the build to break).
Trying to define "word" as size_t triggers a static assertion due to
jsval_layout growing too big.

Therefore, do as the 64-bit little endian code path and just avoid
defining the "word" field.  Tested on ppc64.

--- jsval.h.orig	2015-08-15 10:28:43.716780000 -0400
+++ jsval.h	2015-08-16 22:54:21.456094000 -0400
@@ -304,7 +304,6 @@ typedef union jsval_layout
             int32_t        i32;
             uint32_t       u32;
             JSWhyMagic     why;
-            jsuword        word;
         } payload;
     } s;
     double asDouble;
