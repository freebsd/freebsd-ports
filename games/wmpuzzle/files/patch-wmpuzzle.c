$FreeBSD$

--- wmpuzzle.c.orig	Thu Apr 18 00:13:52 2002
+++ wmpuzzle.c	Wed May 15 21:21:20 2002
@@ -22,6 +22,7 @@
 #include "xpm/eagle.xpm"
 #include "xpm/earth.xpm"
 #include "xpm/linux.xpm"
+#include "xpm/daemon.xpm"
 
 #define PROGRAM_NAME     "wmpuzzle"
 #define PROGRAM_VERSION  "0.1.1"
@@ -203,6 +204,8 @@
 				*wmpuzzle = earth_xpm;
 			else if (!strcmp(optarg, "linux"))
 				*wmpuzzle = linux_xpm;
+			else if (!strcmp(optarg, "daemon"))
+				*wmpuzzle = daemon_xpm;
 			else {
 				fprintf(stderr, "%s: invalid image `%s'\n", PROGRAM_NAME, optarg);
 				exit(1);
@@ -224,7 +227,7 @@
 			printf("Usage: %s [-h] [-i <image>] [-k] [-s <count>] [-v]\n", PROGRAM_NAME);
 			printf("  -h, --help             displays this command line summary.\n");
 			printf("  -i, --image <image>    uses <image>, valid images are `debian', `eagle',\n");
-			printf("                         `earth', and `linux'.\n");
+			printf("                         `earth', `linux', and `daemon'.\n");
 			printf("  -k, --keyboard         enables the arrow keys on the keyboard.\n");
 			printf("  -s, --shuffle <count>  shuffles the image <count> times.\n");
 			printf("  -v, --version          displays the version number.\n");
