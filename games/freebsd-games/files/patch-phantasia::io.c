Index: phantasia/io.c
===================================================================
RCS file: /var/fcvs/src/games/phantasia/Attic/io.c,v
retrieving revision 1.6
diff -u -r1.6 io.c
--- phantasia/io.c	16 Nov 1999 02:57:33 -0000	1.6
+++ phantasia/io.c	10 Sep 2003 09:52:52 -0000
@@ -79,6 +79,9 @@
 	    case CH_NEWLINE:	/* terminate string */
 		break;
 
+	    case CH_CR:	        /* terminate string */
+		break;
+
 	    case CH_REDRAW:	/* redraw screen */
 		clearok(stdscr, TRUE);
 		continue;
@@ -91,7 +94,7 @@
 
 	*inptr = '\0';		/* terminate string */
 	}
-    while (ch != CH_NEWLINE && inptr < cp + mx);
+    while (ch != CH_NEWLINE && ch != CH_CR && inptr < cp + mx);
 }
 /**/
 /************************************************************************
