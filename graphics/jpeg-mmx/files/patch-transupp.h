--- transupp.h.exif	1997-07-24 04:39:12.000000000 +0200
+++ transupp.h	2003-09-25 01:05:12.000000000 +0200
@@ -121,7 +121,8 @@
 typedef enum {
 	JCOPYOPT_NONE,		/* copy no optional markers */
 	JCOPYOPT_COMMENTS,	/* copy only comment (COM) markers */
-	JCOPYOPT_ALL		/* copy all optional markers */
+	JCOPYOPT_ALL,		/* copy all optional markers */
+	JCOPYOPT_EXIF		/* copy Exif APP1 marker */
 } JCOPY_OPTION;
 
 #define JCOPYOPT_DEFAULT  JCOPYOPT_COMMENTS	/* recommended default */
