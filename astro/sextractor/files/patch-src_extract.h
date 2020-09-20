--- src/extract.h.orig	2005-11-30 06:10:08 UTC
+++ src/extract.h
@@ -26,7 +26,7 @@ typedef	enum		{COMPLETE, INCOMPLETE, NONOBJECT, OBJECT
 				status;	/* Extraction status */
 
 /*--------------------------------- variables -------------------------------*/
-PIXTYPE		*dumscan;
+EXTERN PIXTYPE		*dumscan;
 
 /*------------------------------- structures --------------------------------*/
 /* Temporary object parameters during extraction */
