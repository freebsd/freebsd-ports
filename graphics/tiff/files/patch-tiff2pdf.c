--- tools/tiff2pdf.c.orig	2009-01-01 01:10:43.000000000 +0100
+++ tools/tiff2pdf.c	2009-09-14 12:13:39.000000000 +0200
@@ -3726,7 +3726,7 @@
 	written += t2pWriteFile(output, (tdata_t) "(", 1);
 	for (i=0; i<len; i++) {
 		if((pdfstr[i]&0x80) || (pdfstr[i]==127) || (pdfstr[i]<32)){
-			sprintf(buffer, "\\%.3hho", pdfstr[i]);
+			snprintf(buffer, sizeof(buffer), "\\%.3hho", pdfstr[i]);
 			buffer[sizeof(buffer) - 1] = '\0';
 			written += t2pWriteFile(output, (tdata_t) buffer, 4);
 		} else {
