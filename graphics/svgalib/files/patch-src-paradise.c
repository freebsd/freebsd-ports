--- src/paradise.c.orig	2015-01-07 00:08:55.000000000 +0300
+++ src/paradise.c	2015-01-07 00:09:33.000000000 +0300
@@ -40,7 +40,7 @@
 {
 }
 
-void inline _outb(unsigned port,unsigned value)
+static void inline _outb(unsigned port,unsigned value)
 {
 #ifdef DEBUG
  printf ("0x%x, 0x%x\n",port,value);
