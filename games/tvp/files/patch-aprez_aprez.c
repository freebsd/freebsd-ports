
$FreeBSD$

--- aprez/aprez.c.orig	Sun Feb  1 22:31:50 2004
+++ aprez/aprez.c	Sun Feb  1 22:31:21 2004
@@ -484,18 +484,18 @@
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
