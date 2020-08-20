--- arcunp.c.orig	2010-08-07 13:06:42 UTC
+++ arcunp.c
@@ -39,8 +39,8 @@ extern int	lastc;
 #define NOHIST 0		/* no relevant history */
 #define INREP 1			/* sending a repeated value */
 
-short    crcval;		/* CRC check value */
-long     stdlen;		/* bytes to read */
+extern short    crcval;		/* CRC check value */
+extern long     stdlen;		/* bytes to read */
 #if	!DOS
 static int	gotcr;		/* got a carriage return? */
 #endif
@@ -122,7 +122,7 @@ unpack(f, t, hdr)		/* unpack an archive entry */
 		break;
 
 	default:		/* unknown method */
-		if (warn) {
+		if (arcwarn) {
 			printf("I don't know how to unpack file %s\n", hdr->name);
 			printf("I think you need a newer version of ARC\n");
 			nerrs++;
@@ -134,7 +134,7 @@ unpack(f, t, hdr)		/* unpack an archive entry */
 	/* cleanups common to all methods */
 
 	if (crcval != hdr->crc) {
-		if (warn || kludge) {
+		if (arcwarn || kludge) {
 			printf("WARNING: File %s fails CRC check\n", hdr->name);
 			nerrs++;
 		}
