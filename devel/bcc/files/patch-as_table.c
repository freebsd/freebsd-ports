--- as/table.c.orig	1993-07-10 19:08:32 UTC
+++ as/table.c
@@ -849,7 +849,7 @@ PUBLIC struct sym_s *lookup()
 	    hashval ^= hconv(nameptr[-1]);
     }
     else
-	hashval  = hconv(nameptr[-(length / 2)]) * MULTIPLIER,
+	hashval  = hconv(nameptr[-(int) (length / 2)]) * MULTIPLIER,
 	hashval ^= hconv(nameptr[-2]) << 2,
 	hashval ^= hconv(nameptr[-1]);
     nameptr = symname;
