
$FreeBSD$

--- lib/erl_interface/src/decode/decode_big.c.orig
+++ lib/erl_interface/src/decode/decode_big.c
@@ -52,7 +52,10 @@
       u = (unsigned char *) s;
       for (i = 0; i < b->arity; ++i) {
 	  dt[i] = u[i*2];
-	  dt[i] |= ((unsigned short) u[(i*2)+1]) << 8;
+	  if ((i*2 + 1) < digit_bytes)
+	  {
+	       dt[i] |= ((unsigned short) u[(i*2)+1]) << 8;
+	  }
       }
   } else {
       s++; /* skip sign byte */
