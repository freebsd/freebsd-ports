--- src/meny/meny.cc.orig	Fri Sep  2 13:26:36 2005
+++ src/meny/meny.cc	Fri Sep  2 13:27:53 2005
@@ -124,7 +124,7 @@
 	return 1;
 }
 /*****************************************************************************************/
-int Do_Menu(char *text, int num_items, int pos = 1) {
+int Do_Menu(char *text, int num_items, int pos) {
 	PALETTE pal;
 	UrbanFont m(LARGE_FONT);
         m.SetScale(65);
@@ -194,7 +194,7 @@
 #ifdef DJGPP	
 	sprintf(filename, "savegame.dat");
 #else	
-	sprintf(filename, "%s/.urban/savegame.dat", getenv("HOME"));
+	snprintf(filename, sizeof(filename)-1, "%s/.urban/savegame.dat", getenv("HOME"));
 #endif
         if ((fs = fopen(filename, "rb")) == NULL) {
         	for (int i = 0; i < 5;i++) {
@@ -203,10 +203,10 @@
                 }
 #ifndef DJGPP
 		/* Create dir */
-		sprintf(filename, "%s/.urban", getenv("HOME"));
+		snprintf(filename, sizeof(filename)-1, "%s/.urban", getenv("HOME"));
 		mkdir(filename, S_IRUSR | S_IWUSR | S_IXUSR);
 
-		sprintf(filename, "%s/.urban/savegame.dat", getenv("HOME"));
+		snprintf(filename, sizeof(filename)-1, "%s/.urban/savegame.dat", getenv("HOME"));
 #endif
                 if((fs = fopen(filename, "wb")) != NULL) {
 
