--- src/rcsdiff.c
+++ freebsd/gnu/usr.bin/rcs/rcsdiff/rcsdiff.c	1999-08-28 03:37:10.000000000 +0400
@@ -216,7 +215,7 @@ mainProg(rcsdiffId, "rcsdiff", "$Id: rcs
 		    /* fall into */
 	    case 'C': case 'F': case 'I': case 'L': case 'W':
 #if DIFF_L
-		    if (c == 'L'  &&  ++file_labels == 2)
+		    if (c == 'L'  &&  file_labels++ == 2)
 			faterror("too many -L options");
 #endif
 		    *dcp++ = c;
