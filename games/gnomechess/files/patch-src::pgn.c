--- src/pgn.c.orig	Thu Jun 28 06:14:20 2001
+++ src/pgn.c	Sun Aug 22 03:44:44 2004
@@ -311,6 +311,7 @@
 		tag->result = g_strdup(value2.v_string);
 		break;
 	default:
+		;
 	}
 }
 
@@ -512,6 +513,7 @@
 	}
 
  finish:
+	;
 }
 
 static int 
