--- rat4.c.orig	Wed Mar 20 16:58:50 1996
+++ rat4.c	Sat Aug 26 22:58:11 2000
@@ -36,2 +36,3 @@
 #include <stdio.h>
+#include <unistd.h>
 
@@ -162,3 +163,3 @@
 
-	while ((c=our_getopt(argc, argv, "Chn:o:6:")) != EOF)
+	while ((c=getopt(argc, argv, "Chl:n:o:6:")) != EOF)
 	switch (c) {
@@ -193,6 +194,6 @@
 	 */
-	if (optind77 >= argc)
+	if (optind >= argc)
 		infile[0] = stdin;
-	else if ((infile[0] = fopen(argv[optind77], "r")) == NULL)
-		error("cannot read %s\n", argv[optind77]);
+	else if ((infile[0] = fopen(argv[optind], "r")) == NULL)
+		error("cannot read %s\n", argv[optind]);
 
