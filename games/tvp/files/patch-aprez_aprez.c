
$FreeBSD$

--- aprez/aprez.c.orig
+++ aprez/aprez.c
@@ -266,6 +266,7 @@
 			    SGBtot[3][0], SGBtot[3][1], SGBtot[3][2],
 			    SGBtot[3][3]);
 dontdothis:
+			1;
 		}  /* if (!ass_turn (game)) */
 
 		/* Take someone's turn... */
@@ -484,18 +485,18 @@
 		tcsetattr (fileno(stdin), TCSANOW, &term);
 	}
 	if (i == 'h') {
-		bigmessage ("
-j\tdown one
-u\tup one
-s\ttoggle select on card
-l\tlay (or pass if no cards are selected)
-v\tsave game
-b\tload game
-h\tcommand reference
-w\twarranty and license
-a\tabout
-C-C\tquit (Ctrl-C)
-");
+		bigmessage ("\n"
+"j\tdown one\n"
+"u\tup one\n"
+"s\ttoggle select on card\n"
+"l\tlay (or pass if no cards are selected)\n"
+"v\tsave game\n"
+"b\tload game\n"
+"h\tcommand reference\n"
+"w\twarranty and license\n"
+"a\tabout\n"
+"C-C\tquit (Ctrl-C)\n"
+"");
 	}
 	if (i == 'w') {
 		mondomessage ("!COPYING!");
