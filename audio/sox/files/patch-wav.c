--- wav.c.old	2002-12-31 04:19:22.000000000 +0100
+++ wav.c	2004-07-18 19:25:46.000000000 +0200
@@ -917,6 +917,10 @@
 		} else if(strncmp(magic,"ICRD",4) == 0){
 			st_readdw(ft,&len); 
 			len = (len + 1) & ~1;
+			if (len > 254) {
+			    fprintf(stderr, "Possible buffer overflow hack attack (ICRD)!\n");
+			    exit(109);
+			}
 			st_reads(ft,text,len);
 			if (strlen(ft->comment) + strlen(text) < 254)
 			{
@@ -926,6 +930,10 @@
 		} else if(strncmp(magic,"ISFT",4) == 0){
 			st_readdw(ft,&len); 
 			len = (len + 1) & ~1;
+			if (len > 254) {
+			    fprintf(stderr, "Possible buffer overflow hack attack (ISFT)!\n");
+			    exit(110);
+			}
 			st_reads(ft,text,len);
 			if (strlen(ft->comment) + strlen(text) < 254)
 			{
