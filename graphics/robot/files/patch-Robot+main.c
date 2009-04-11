--- Robot/main.c.orig	2005-05-03 17:14:51.000000000 +0200
+++ Robot/main.c	2009-04-11 21:57:57.000000000 +0200
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
 
@@ -2130,7 +2130,7 @@
 /* remove trailing blanks */
 	for (i = 0; i < strlen(instruction); i++){
 		if(instruction[i] == ' ') 
-			instruction[i] = (char) NULL;}
+			instruction[i] = 0;}
 	activate(instruction);
 }
 
@@ -3063,7 +3063,7 @@
 
 
 	strncpy(direc, dir, *n);
-	direc[*n] = (char) NULL;
+	direc[*n] = 0;
 
 /* null directory path is assumed to be cd to home */
 
@@ -3915,7 +3915,7 @@
 		&& strlen(sys_buffer) > 4)
 			sys_buffer[strlen(sys_buffer) - strlen(".rob")]
 
-				= (char) NULL;
+				= 0;
 
 /* Only add a .ps if there isn't one there to start with */
 	if(!taileq(sys_buffer, ".ps")) strcat(sys_buffer, ".ps");
