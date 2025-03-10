--- uip/mshcmds.c.orig
+++ uip/mshcmds.c
@@ -29,8 +29,6 @@
 
 /*  */
 
-extern int errno;
-
 				/* BURST */
 static char delim3[] = "-------";/* from burst.c */
 
@@ -3529,7 +3527,6 @@
     (void) strcpy (tmpfil, m_scratch ("", invo_name));
     if ((out = fopen (tmpfil, "w")) == NULL) {
 	int     olderr;
-	extern int  errno;
 	char    newfil[80];
 
 	olderr = errno;
