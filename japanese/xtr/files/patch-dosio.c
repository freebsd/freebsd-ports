--- src/dosio.c.orig	Tue Nov  5 18:29:49 2002
+++ src/dosio.c	Tue Nov  5 18:30:30 2002
@@ -287,12 +287,14 @@
 {
 	static int raw_mode = 0;
 
-	if (close_tty)
-		FError("There is no control-terminal.");
-
 #if HAVE_TERMIOS_H && HAVE_TERMIOS_FUNCS
 	struct termios s;
 	static struct termios os;
+#endif
+
+#if HAVE_TERMIOS_H && HAVE_TERMIOS_FUNCS
+	if (close_tty)
+		FError("There is no control-terminal.");
 
 	if (flag > 0) {
 		tcgetattr(fileno(stdin), &s);
