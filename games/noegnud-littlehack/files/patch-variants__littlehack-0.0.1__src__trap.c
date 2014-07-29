--- variants/littlehack-0.0.1/src/trap.c.orig	Fri Feb 18 13:35:53 2005
+++ variants/littlehack-0.0.1/src/trap.c	Fri Feb 18 13:37:22 2005
@@ -845,6 +845,7 @@
 		    }
 		    break;
 		}
+	    {
 		    char verbbuf[BUFSZ];
 #ifdef STEED
 		    if (u.usteed) {
@@ -862,6 +863,7 @@
 #endif
 		    Strcpy(verbbuf,"fall");
 		    You("%s into %s pit!", verbbuf, a_your[trap->madeby_u]);
+	    }
 		/* wumpus reference */
 		if (u.umonnum == PM_PIT_VIPER ||
 			u.umonnum == PM_PIT_FIEND)
