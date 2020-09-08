--- plugins/bladesio1/sio1.c.orig	2020-09-07 22:26:23 UTC
+++ plugins/bladesio1/sio1.c
@@ -55,8 +55,6 @@ static const unsigned char build	= 1;
 
 static void (CALLBACK *irqCallback)() = 0;
 
-Settings settings;
-
 /* sio status flags.
  */
 enum {
