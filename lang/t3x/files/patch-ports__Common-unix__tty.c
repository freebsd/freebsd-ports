--- ports/Common-unix/tty.c.orig	2004-02-22 01:18:15.000000000 +0300
+++ ports/Common-unix/tty.c	2014-04-24 21:18:57.390972992 +0400
@@ -258,7 +258,7 @@
 	int	f, b, h;
 	char	buf[40];
 
-	if (tty_attr == c) return;
+	if (tty_attr == c) return 0;
 	tty_attr = c;
 	f = ctab[c & 7];
 	b = ctab[(c>>4) & 7];
@@ -283,6 +283,7 @@
 			tty_soflag = (b>f);
 		}
 	}
+	return 0;
 }
 
 XCELL ttyctl_color S1(XCELL c) {
