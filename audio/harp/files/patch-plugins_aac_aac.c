--- plugins/aac/aac.c.orig	2021-04-10 21:47:11 UTC
+++ plugins/aac/aac.c
@@ -25,7 +25,7 @@
 
 #include "aacmeta.c"
 
-struct aacHandles{
+static struct aacHandles{
 	volatile unsigned int *total;
 	volatile unsigned int *sample;
 	unsigned int *rate;
