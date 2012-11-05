--- utils/fontdata.c.orig	2012-11-05 15:44:52.000000000 -0500
+++ utils/fontdata.c	2012-11-05 15:42:54.000000000 -0500
@@ -39,7 +39,8 @@
 {
 	int x;
 	unsigned char line, input;
-	FILE *infile, *outfile;
+	gzFile infile;
+	FILE *outfile;
 	
 	if (argc==2)
 		infile=gzopen(argv[1],"rb");
