--- ./common/packets.c.orig	Mon Mar  6 06:35:23 2006
+++ ./common/packets.c	Tue Sep 26 11:21:55 2006
@@ -577,6 +577,7 @@
 	  chunk->total_length, chunk->chunk_length);
 
   if (chunk->total_length < 0
+      || chunk->chunk_length < 0
       || chunk->total_length >= MAX_ATTRIBUTE_BLOCK
       || chunk->offset < 0
       || chunk->offset + chunk->chunk_length > chunk->total_length
