
$FreeBSD$

--- lib/erl_interface/src/decode/decode_longlong.c.orig	Sun Aug 31 14:00:44 2003
+++ lib/erl_interface/src/decode/decode_longlong.c	Sun Aug 31 14:01:41 2003
@@ -51,7 +51,7 @@
 	int pos, shift = 0;
 	n = 0;
 	for (pos = 0; pos < arity; pos++) {
-	    n |= get8(s) << shift;
+	    n |= ((EI_LONGLONG) get8(s)) << shift;
 	    shift += 8;
 	}
     }
