--- db.c.orig	Sat Jan  3 08:43:09 2004
+++ db.c	Sat Jan  3 08:43:43 2004
@@ -90,7 +90,6 @@
 DB	*db;
 char	*outputsep = "\t";
 int	encflags = 0;
-char	*extra_echars = NULL;
 
 int
 main(int argc, char *argv[])
@@ -120,7 +119,7 @@
 
 				/* parse arguments */
 	while ( (ch = getopt(argc, argv,
-			     "CDdE:F:f:iKm:NO:qRS:T:U:VwX:")) != -1) {
+			     "CDdE:F:f:iKm:NO:qRS:T:U:Vw")) != -1) {
 		switch (ch) {
 
 		case 'C':
@@ -224,10 +223,6 @@
 			flags |= F_WRITE;
 			break;
 
-		case 'X':
-			extra_echars = optarg;
-			break;
-
 		default:
 			usage();
 
@@ -548,11 +543,7 @@
 		buflen = elen;
 	}
 	*edata = buf;
-	if (extra_echars) {
-		return (strsvisx(buf, data, len, encflags, extra_echars));
-	} else {
-		return (strvisx(buf, data, len, encflags));
-	}
+	return (strvisx(buf, data, len, encflags));
 }
 
 int
@@ -625,7 +616,7 @@
 	const char *p = getprogname();
 
 	fprintf(stderr,
-    "Usage: %s [-KiNqV] [-E end] [-f inf] [-O str] [-S chr] [-T str] [-X str]\n"
+    "Usage: %s [-KiNqV] [-E end] [-f inf] [-O str] [-S chr] [-T str] \n"
     "             type dbfile [key [...]]\n"
     "       %s -d [-iNq] [-E end] [-f inf] [-U chr] type dbfile [key [...]]\n"
     "       %s -w [-CDiNqR] [-E end] [-F sep] [-f inf] [-m mod] [-U chr]\n"
@@ -653,7 +644,6 @@
 	    "\t-T str\toptions to control -S encoding like vis(1) options\n"
 	    "\t-U chr\titems to strunvis(3) decode: 'k'ey, 'v'alue, 'b'oth\n"
 	    "\t-V\tprint value\n"
-	    "\t-X str\textra characters to encode with -S\n"
 	    );
 	exit(1);
 }
