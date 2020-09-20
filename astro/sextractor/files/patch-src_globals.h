--- src/globals.h.orig	2006-07-14 14:28:10 UTC
+++ src/globals.h
@@ -18,13 +18,13 @@
 
 /*----------------------- miscellaneous variables ---------------------------*/
 
-sexcatstruct		thecat;
-picstruct		thefield1,thefield2, thewfield1,thewfield2;
-objstruct		flagobj;
-obj2struct		flagobj2;
+EXTERN sexcatstruct	thecat;
+EXTERN picstruct	thefield1,thefield2, thewfield1,thewfield2;
+EXTERN objstruct	flagobj;
+EXTERN obj2struct	flagobj2;
 extern obj2struct	outobj2;
-float			ctg[37], stg[37];
-char			gstr[MAXCHAR];
+EXTERN float		ctg[37], stg[37];
+EXTERN char		gstr[MAXCHAR];
 
 /*------------------------------- functions ---------------------------------*/
 extern void	allocparcelout(void),
@@ -81,6 +81,6 @@ extern void	*loadstrip(picstruct *, picstruct *);
 
 extern char	*readfitshead(FILE *, char *, int *);
 
-extern picstruct	*inheritfield(picstruct *infield, int flags),
+extern picstruct *inheritfield(picstruct *infield, int flags),
 			*newfield(char *, int , int);
 
