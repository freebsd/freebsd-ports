--- numbers.c.orig	Wed Nov 30 11:06:26 2005
+++ numbers.c	Sun Jan  8 22:22:04 2006
@@ -980,14 +980,14 @@
 
 	case 329:		/* #define CREATION_TIME 329 */
 	    {
-		time_t tme;
+		unsigned long tme;
 		char *this_sucks;
 		struct channel *chan = NULL;
 
 		if (!ArgList[1] || !*ArgList[1])
 		    break;
 		sscanf(ArgList[1], "%lu", &tme);
-		this_sucks = ctime(&tme);
+		this_sucks = ctime((time_t *)&tme);
 		this_sucks[strlen(this_sucks) - 1] = '\0';
 
 		message_from(ArgList[0], LOG_CRAP);
