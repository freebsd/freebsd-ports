--- Robot/main.c.orig	Tue May  3 17:14:51 2005
+++ Robot/main.c	Wed Dec 28 17:02:15 2005
@@ -561,19 +561,19 @@
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
-For more information see help available in the program under\n\
-the \"About\" option or visit:\n\
-%s\n", msize, WEB_HELP);
+			printf("robot (generic-tool-options)\n");
+			printf("-arraysize [size of arrays, default is %d]\n");
+			printf("-plotscale [scale factor]\n");
+			printf("-portrait\n");
+			printf("-landscape         (default)\n");
+			printf("-notol             (not Open-look - adds some extra quit buttons)\n");
+			printf("-stdin             (reads commands from standard input instead of GUI)\n");
+			printf("-v		   (print version number and quit)\n");
+			printf("-help/-h           (prints this information and quits)\n");
+			printf("(optional command file name)\n\n");
+			printf("For more information see help available in the program under\n");
+			printf("the \"About\" option or visit:\n");
+			printf("%s\n", msize, WEB_HELP);
 			fstop_();
 		}
 
