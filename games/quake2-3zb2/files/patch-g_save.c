--- ./g_save.c.orig	Sat Dec 30 19:09:03 2006
+++ ./g_save.c	Sat Dec 30 19:09:23 2006
@@ -202,7 +202,9 @@
 	bob_up  = gi.cvar ("bob_up", "0.005", 0);
 	bob_pitch = gi.cvar ("bob_pitch", "0.002", 0);
 	bob_roll = gi.cvar ("bob_roll", "0.002", 0);
-
+	
+	botchat = gi.cvar ("botchat", "1", CVAR_ARCHIVE);
+	
 	// items
 	InitItems ();
 
@@ -295,6 +297,8 @@
 			len = strlen(*(char **)p) + 1;
 			fwrite (*(char **)p, len, 1, f);
 		}
+		break;
+	default:
 		break;
 	}
 }
