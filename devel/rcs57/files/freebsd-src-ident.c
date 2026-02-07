--- src/ident.c
+++ freebsd/gnu/usr.bin/rcs/ident/ident.c
@@ -234,7 +233,7 @@ match(fp)   /* group substring between t
       if (c == EOF  &&  feof(fp) | ferror(fp))
 	 return c;
       switch (ctab[c]) {
-	 case LETTER: case Letter:
+	 case LETTER: case Letter: case DIGIT:
 	    *tp++ = c;
 	    if (tp < line+sizeof(line)-4)
 	       break;
