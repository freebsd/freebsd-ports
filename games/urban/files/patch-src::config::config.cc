--- src/config/config.cc.orig	Fri Sep  2 13:26:20 2005
+++ src/config/config.cc	Fri Sep  2 13:27:53 2005
@@ -24,7 +24,7 @@
 #ifdef DJGPP
 	sprintf(filename, "ctrl.dat");
 #else
-	sprintf(filename, "%s/.urban/ctrl.dat", getenv("HOME"));
+	snprintf(filename, sizeof(filename)-1, "%s/.urban/ctrl.dat", getenv("HOME")); 
 #endif
 
         if(!(fd = fopen(filename, "rb")))
@@ -43,10 +43,10 @@
 	sprintf(filename, "ctrl.dat");
 #else
 	/* Create dir */
-	sprintf(filename, "%s/.urban", getenv("HOME"));
+	snprintf(filename, sizeof(filename)-1,  "%s/.urban", getenv("HOME"));  
 	mkdir(filename, S_IRUSR | S_IWUSR | S_IXUSR);
 
-	sprintf(filename, "%s/.urban/ctrl.dat", getenv("HOME"));
+	snprintf(filename, sizeof(filename)-1, "%s/.urban/ctrl.dat", getenv("HOME"));
 #endif
         if(!(fd = fopen(filename, "wb")))
         	return;
@@ -91,10 +91,10 @@
 	/* Ask for the number of buttons */
 
         fnt.print_centre("Gamepad type:", 160, 100);
-	fnt.print_centre("  1. 2 buttons
-  2. 4 buttons
-  3. 6 buttons
-  4. 8 buttons", 160, 140);
+	fnt.print_centre("  1. 2 buttons"
+"  2. 4 buttons"
+"  3. 6 buttons"
+"  4. 8 buttons", 160, 140);
 	int running = 1;
 
 	while(running) {
