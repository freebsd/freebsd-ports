--- Arch/PCux/audio.c.orig	Sat Jun 12 22:19:39 2004
+++ Arch/PCux/audio.c	Sat Jun 12 22:19:57 2004
@@ -149,6 +149,7 @@
 		add_samples8(left, right, n);
 		break;
 	default:	/* should not happen */
+		break;
 	   }
    }
 
