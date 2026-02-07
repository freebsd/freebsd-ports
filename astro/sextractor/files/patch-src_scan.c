--- src/scan.c.orig	2006-06-29 20:03:13 UTC
+++ src/scan.c
@@ -49,6 +49,9 @@ NOTES   -.
 AUTHOR  E. Bertin (IAP)
 VERSION 29/11/2005
  ***/
+
+PIXTYPE		*dumscan;
+
 void	scanimage(picstruct *field, picstruct *dfield, picstruct **pffield,
 		int nffield, picstruct *wfield, picstruct *dwfield)
 
