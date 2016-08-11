--- mouse.c.orig	1996-03-07 17:34:43 UTC
+++ mouse.c
@@ -266,7 +266,7 @@ int	mproto;
 	/* Format of command to xterm to start or stop mouse hilite tracking:
 	 * ^[ [ func ; startx ; starty ; firstrow ; lastrow T
 	 */
-#define XTERMBUG
+/* #undef XTERMBUG */
 #ifdef XTERMBUG
 	static const char	hl_fmt[] = "\033[%d;%d;%d;%d;%dTX";
 #else
