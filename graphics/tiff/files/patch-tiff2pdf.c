CVE-2006-2193
===================================================================
--- tools/tiff2pdf.c.orig	2006-06-04 18:26:40.000000000 -0700
+++ tools/tiff2pdf.c	2006-06-04 18:27:22.000000000 -0700
@@ -3668,7 +3668,7 @@
 	written += TIFFWriteFile(output, (tdata_t) "(", 1);
 	for (i=0;i<len;i++){
 		if((pdfstr[i]&0x80) || (pdfstr[i]==127) || (pdfstr[i]<32)){
-			sprintf(buffer, "\\%.3o", pdfstr[i]);
+			snprintf(buffer, sizeof(buffer), "\\%.3o", pdfstr[i]);
 			written += TIFFWriteFile(output, (tdata_t) buffer, 4);
 		} else {
 			switch (pdfstr[i]){
