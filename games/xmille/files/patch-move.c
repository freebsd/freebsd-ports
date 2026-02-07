--- move.c.orig	Thu Mar 28 15:13:44 1996
+++ move.c	Fri Jun 15 02:33:02 2007
@@ -9,15 +9,16 @@
 #endif
 #define	CTRL(c)		(c - 'A' + 1)
 
-#define ANIMATE 1
-
 /*extern FILE *outf;*/
 
 char	*Movenames[] = {
 		"M_DISCARD", "M_DRAW", "M_PLAY", "M_ORDER"
 	};
 
-char	*playcard (), *sprint ();
+char	*playcard (), 
+        *sprintDecimal( char* format, int arg ),
+        *sprintString( char* format, char* arg );
+
 
 domove()
 {
@@ -203,7 +204,7 @@
 			return ("limit of 50");
 	  case C_50:
 		if (pp->mileage + Value[card] > End)
-			return sprint ("puts you over %d", End);
+			return sprintDecimal ("puts you over %d", End);
 	  case C_25:
 		if (!pp->can_go)
 			return ("cannot move now");
@@ -220,7 +221,7 @@
 
 	  case C_GAS:	case C_SPARE:	case C_REPAIRS:
 		if (pp->battle != opposite(card))
-			return sprint ("can't play \"%s\"", C_name[card]);
+			return sprintString ("can't play \"%s\"", C_name[card]);
 #ifdef ANIMATE
 		animate_move (Play, ANIMATE_HAND, Card_no, ANIMATE_BATTLE, card);
 #endif
@@ -232,7 +233,7 @@
 	  case C_GO:
 		if (pp->battle != C_INIT && pp->battle != C_STOP
 		    && !isrepair(pp->battle))
-			return sprint ("cannot play \"Go\"on a \"%s\"",
+			return sprintString ("cannot play \"Go\"on a \"%s\"",
 			    C_name[pp->battle]);
 #ifdef ANIMATE
 		animate_move (Play, ANIMATE_HAND, Card_no, ANIMATE_BATTLE, card);
@@ -339,12 +340,19 @@
 	return 0;
 }
 
-char *
-sprint (string, arg)
+char* sprintDecimal( char* format, int arg )
+{
+	static char	buf[512];
+
+	sprintf (buf, format, arg);
+	return buf;
+}
+
+char* sprintString( char* format, char* arg )
 {
 	static char	buf[512];
 
-	sprintf (buf, string, arg);
+	sprintf (buf, format, arg);
 	return buf;
 }
 
