--- AltairZ80/i86_prim_ops.c.orig	2017-10-12 22:55:55 UTC
+++ AltairZ80/i86_prim_ops.c
@@ -1488,7 +1488,7 @@ void div_byte(PC_ENV *m, uint8 s)
     }
     div = dvd / dvs;
     mod = dvd % dvs;
-    if (abs(div) > 0xff)
+    if (div > 0xff)
     {
        i86_intr_raise(m,0);
        return;
@@ -1514,7 +1514,7 @@ void div_word(PC_ENV *m, uint16 s)
     div = dvd / dvs;
     mod = dvd % dvs;
 /*    printf("dvd=%x dvs=%x -> div=%x mod=%x\n",dvd, dvs,div, mod);*/
-    if (abs(div) > 0xffff)
+    if (div > 0xffff)
     {
        i86_intr_raise(m,0);
        return;
