--- ./arcunp.c.orig	Tue Aug 10 23:03:25 1999
+++ ./arcunp.c	Tue Aug 10 23:01:57 1999
@@ -123,7 +123,7 @@
 		break;
 
 	default:		/* unknown method */
-		if (warn) {
+		if (arcwarn) {
 			printf("I don't know how to unpack file %s\n", hdr->name);
 			printf("I think you need a newer version of ARC\n");
 			nerrs++;
@@ -135,7 +135,7 @@
 	/* cleanups common to all methods */
 
 	if (crcval != hdr->crc) {
-		if (warn || kludge) {
+		if (arcwarn || kludge) {
 			printf("WARNING: File %s fails CRC check\n", hdr->name);
 			nerrs++;
 		}
