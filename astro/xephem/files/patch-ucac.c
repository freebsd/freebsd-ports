--- ucac.c.orig	2013-03-02 02:41:37 UTC
+++ ucac.c
@@ -18,15 +18,15 @@
 
 #define	MAXFOV	15.0			/* max fov, degs */
 
-typedef unsigned char UC;		/* byte */
-typedef unsigned int UI;		/* unsigned integer */
+typedef unsigned char XE_UC;		/* byte */
+typedef unsigned int XE_UI;		/* unsigned integer */
 
 /* access an I*2 or I*4 at offset i in UC array a in little-endian byte order.
  * a bit slow but ultra portable.
  */
-#define	I2(a,i)		((int)(short)((((UI)(a)[i]) | (((UI)(a)[i+1])<<8))))
-#define	I4(a,i)		((int)((((UI)(a)[i]) | (((UI)(a)[i+1])<<8) | \
-				(((UI)(a)[i+2])<<16) | (((UI)(a)[i+3])<<24))))
+#define	I2(a,i)		((int)(short)((((XE_UI)(a)[i]) | (((XE_UI)(a)[i+1])<<8))))
+#define	I4(a,i)		((int)((((XE_UI)(a)[i]) | (((XE_UI)(a)[i+1])<<8) | \
+				(((XE_UI)(a)[i+2])<<16) | (((XE_UI)(a)[i+3])<<24))))
 
 /* keep track of an array of ObjF */
 typedef struct {
@@ -48,9 +48,9 @@ typedef struct {
 
 #define	DPMAS	(1.0/3600000.0)		/* degrees per milliarcsecond */
 
-typedef UC U2Star[44];			/* UCAC2 record */
-typedef UC U3Star[84];			/* UCAC3 record */
-typedef UC U4Star[78];			/* UCAC4 record */
+typedef XE_UC U2Star[44];		/* UCAC2 record */
+typedef XE_UC U3Star[84];		/* UCAC3 record */
+typedef XE_UC U4Star[78];		/* UCAC4 record */
 static char *basedir;			/* full dir with zone files and index */
 static FILE *indexfp;			/* index file handle */
 
@@ -293,7 +293,7 @@ static int
 read4Index (int rz, int dz, int *nskip, int *nnew)
 {
 	off_t offset;
-	UC i4[4];
+	XE_UC i4[4];
 
 	offset = (rz*NZH4 + dz)*sizeof(i4);
 	if (fseek (indexfp, offset, SEEK_SET) < 0) {
@@ -508,7 +508,7 @@ static int
 read3Index (int rz, int dz, int *nskip, int *nnew)
 {
 	off_t offset;
-	UC i4[4];
+	XE_UC i4[4];
 
 	offset = (rz*NZH + dz)*sizeof(i4);
 	if (fseek (indexfp, offset, SEEK_SET) < 0) {
@@ -663,7 +663,7 @@ static int
 get2N (int rz, int dz, int *idp)
 {
 	off_t offset;
-	UC nat[4];
+	XE_UC nat[4];
 
 	offset = (dz*NZW + rz)*sizeof(nat);
 	if (fseek (indexfp, offset, SEEK_SET) < 0)
