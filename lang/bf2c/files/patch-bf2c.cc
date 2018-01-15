--- bf2c.cc.orig	2013-06-12 22:11:38 UTC
+++ bf2c.cc
@@ -57,7 +57,7 @@ int main(int argc, char *argv[]) {
 	pt = NULL;
 	infname = outfname = invchar = NULL;
 
-	printf("bf2c.cc "VERSION" Copyright (c) 2002-"ENDYEAR" Rene Ladan <r.c.ladan@gmail.com>\n\n"
+	printf("bf2c.cc " VERSION " Copyright (c) 2002-" ENDYEAR " Rene Ladan <r.c.ladan@gmail.com>\n\n"
 		"Optimizing BrainFuck to C compiler.\n\n");
 
 	while ((opt = getopt(argc,argv,"i:o:hs:r:")) != -1) {
