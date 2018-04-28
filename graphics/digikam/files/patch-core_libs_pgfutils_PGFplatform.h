--- core/libs/pgfutils/PGFplatform.h.orig	2016-11-06 10:43:01 UTC
+++ core/libs/pgfutils/PGFplatform.h
@@ -485,7 +485,7 @@ __inline int MulDiv(int nNumber, int nNu
 #define FSFromStart			SEEK_SET
 #define FSFromCurrent		SEEK_CUR
 #define FSFromEnd			SEEK_END
-#define nullptr				NULL
+
 
 //-------------------------------------------------------------------------------
 // IO Error constants
