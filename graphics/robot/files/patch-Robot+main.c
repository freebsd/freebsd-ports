--- Robot/main.c.orig	Sat Oct 11 13:14:19 2003
+++ Robot/main.c	Sat Oct 11 13:22:51 2003
@@ -539,20 +539,19 @@
 			 || streq(argv[i], "--help") ){ 
 			printf("Robot version %-1.2f patch  %d\n\n",
 				VERSION, PATCHLEVEL);
-			printf("robot (generic-tool-options)\n\
--arraysize [size of arrays, default is %d]\n\
--plotscale [scale factor]\n\
--portrait\n\
--landscape         (default)\n\
--notol             (not Open-look - adds some extra quit buttons)\n\
--stdin             (reads commands from standard input instead of GUI)\n\
--v		   (print version number and quit)\n\
--help/-h           (prints this information and quits)\n\
-(optional command file name)\n\n\
+			printf("robot (generic-tool-options)\n");
+printf("-arraysize [size of arrays, default is %d]\n");
+printf("-plotscale [scale factor]\n");
+printf("-portrait\n");
+printf("-landscape         (default)\n");
+printf("-notol             (not Open-look - adds some extra quit buttons)\n");
+printf("-stdin             (reads commands from standard input instead of GUI)\n");
+printf("-v		   (print version number and quit)\n");
+printf("-help/-h           (prints this information and quits)\n");
+printf("(optional command file name)\n\n");
 
-For more information see help available in the program under\n\
-the \"About\" option or visit:\n\
-%s\n", msize, WEB_HELP);
+printf("For more information see help available in the program under\n");
+printf("the \"About\" option or visit:\n\%s\n", msize, WEB_HELP);
 			fstop_();
 		}
 
