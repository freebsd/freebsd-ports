--- usno.c.orig	2005-03-20 11:04:51 UTC
+++ usno.c
@@ -14,8 +14,8 @@
 #define	CATBPR	12	/* bytes per star record in .cat file */
 #define	ACCBPR	30	/* bytes per record in .acc file */
 
-typedef unsigned int UI;
-typedef unsigned char UC;
+typedef unsigned int XE_UI;
+typedef unsigned char XE_UC;
 
 /* One Field star */
 typedef struct {
@@ -36,7 +36,7 @@ static int corner (double r0, double d0, double rov, i
     double lr[2], int *nd, double fd[2], double ld[2], int zone[2], char msg[]);
 static int fetchSwath (int zone, double maxmag, double fr, double lr,
     double fd, double ld, StarArray *sap, char msg[]);
-static int crackCatBuf (UC buf[CATBPR], FieldStar *fsp);
+static int crackCatBuf (XE_UC buf[CATBPR], FieldStar *fsp);
 static int addGS (StarArray *sap, FieldStar *fsp);
 
 static char *cdpath;		/* where CD rom is mounted */
@@ -236,7 +236,7 @@ double ld, StarArray *sap, char msg[])
 {
 	char fn[1024];
 	char buf[ACCBPR];
-	UC catbuf[CATBPR];
+	XE_UC catbuf[CATBPR];
 	FieldStar fs;
 	long frec;
 	long os;
@@ -314,13 +314,13 @@ double ld, StarArray *sap, char msg[])
  * return 0 if ok, else -1.
  */
 static int
-crackCatBuf (UC buf[CATBPR], FieldStar *fsp)
+crackCatBuf (XE_UC buf[CATBPR], FieldStar *fsp)
 {
-#define	BEUPACK(b) (((UI)((b)[0])<<24) | ((UI)((b)[1])<<16) | ((UI)((b)[2])<<8)\
-							    | ((UI)((b)[3])))
+#define	BEUPACK(b) (((XE_UI)((b)[0])<<24) | ((XE_UI)((b)[1])<<16) | ((XE_UI)((b)[2])<<8)\
+							    | ((XE_UI)((b)[3])))
 	double ra, dec;
 	int red, blu;
-	UI mag;
+	XE_UI mag;
 
 	/* first 4 bytes are packed RA, big-endian */
 	ra = BEUPACK(buf)/(100.0*3600.0*15.0);
