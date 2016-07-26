--- macunpack/dd.c.orig	1993-10-02 20:16:00 UTC
+++ macunpack/dd.c
@@ -45,7 +45,7 @@ static int dd_getbits();
 #endif /* UNTESTED */
 static void dd_cpt_compat();
 
-typedef struct methodinfo {
+struct methodinfo {
 	char *name;
 	int number;
 };
