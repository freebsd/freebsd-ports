--- arcunp.c.orig	2010-08-07 13:06:42 UTC
+++ arcunp.c
@@ -122,7 +122,7 @@ unpack(f, t, hdr)		/* unpack an archive 
 		break;
 
 	default:		/* unknown method */
-		if (warn) {
+		if (arcwarn) {
 			printf("I don't know how to unpack file %s\n", hdr->name);
 			printf("I think you need a newer version of ARC\n");
 			nerrs++;
@@ -134,7 +134,7 @@ unpack(f, t, hdr)		/* unpack an archive 
 	/* cleanups common to all methods */
 
 	if (crcval != hdr->crc) {
-		if (warn || kludge) {
+		if (arcwarn || kludge) {
 			printf("WARNING: File %s fails CRC check\n", hdr->name);
 			nerrs++;
 		}
