--- src/memory.c.orig	Fri Jan 24 00:01:36 2003
+++ src/memory.c	Fri Jan 24 00:01:51 2003
@@ -492,7 +492,6 @@
 
 uae_u8 REGPARAM2 *default_xlate (uaecptr a)
 {
-    write_log ("Your Amiga program just did something terribly stupid\n");
     uae_reset();
     return kickmem_xlate (get_long (0xF80000)); /* So we don't crash. */
 }
