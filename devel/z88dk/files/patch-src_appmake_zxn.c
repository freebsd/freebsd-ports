--- src/appmake/zxn.c.orig	2020-08-15 03:00:06 UTC
+++ src/appmake/zxn.c
@@ -31,6 +31,7 @@ static struct zx_tape zxt = {
     NULL,       // merge
     -1,         // patchpos
     -1,         // clear_address
+    -1,         // usr_address
     NULL,       // patchdata
     NULL,       // screen
     0,          // audio
