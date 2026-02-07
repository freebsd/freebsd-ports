--- src/rcskeep.c
+++ freebsd/gnu/usr.bin/rcs/lib/rcskeep.c	1999-08-28 03:37:10.000000000 +0400
@@ -192,6 +191,7 @@ getoldkeys(fp)
                 break;
             case Header:
             case Id:
+	    case LocalId:
 		if (!(
 		      getval(fp, (struct buf*)0, false) &&
 		      keeprev(fp) &&
