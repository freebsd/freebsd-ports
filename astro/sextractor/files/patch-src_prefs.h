--- src/prefs.h.orig	2006-07-13 17:11:09 UTC
+++ src/prefs.h
@@ -206,7 +206,7 @@ typedef struct
   int		nthreads;			/* Number of active threads */
   }	prefstruct;
 
-  prefstruct		prefs;
+EXTERN prefstruct	prefs;
 
 /*-------------------------------- protos -----------------------------------*/
 extern int	cistrcmp(char *cs, char *ct, int mode);
