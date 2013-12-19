--- trans.c.orig
+++ trans.c
@@ -23,6 +23,8 @@
 #include "trans.h"
 
 #include <time.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 
 
@@ -575,7 +577,7 @@
 # endif
 #endif
 
-Static long starting_time;
+Static time_t starting_time;
 
 Static void openlogfile()
 {
@@ -588,17 +590,17 @@
     if (!name)
 	name = format_s("%s.log", codefname);
     saveoldfile(name);
-    logf = fopen(name, "w");
-    if (logf) {
-	fprintf(logf, "\nTranslation of %s to %s by p2c %s\n",
+    p2c_logf = fopen(name, "w");
+    if (p2c_logf) {
+	fprintf(p2c_logf, "\nTranslation of %s to %s by p2c %s\n",
 		infname, codefname, P2C_VERSION);
-	fprintf(logf, "Translated");
+	fprintf(p2c_logf, "Translated");
 	uname = getenv("USER");
 	if (uname)
-	    fprintf(logf, " by %s", uname);
+	    fprintf(p2c_logf, " by %s", uname);
 	time(&starting_time);
-	fprintf(logf, " on %s", ctime(&starting_time));
-	fprintf(logf, "\n\n");
+	fprintf(p2c_logf, " on %s", ctime(&starting_time));
+	fprintf(p2c_logf, "\n\n");
     } else {
 	perror(name);
 	verbose = 0;
@@ -608,20 +610,20 @@
 
 void closelogfile()
 {
-    long ending_time;
+    time_t ending_time;
 
-    if (logf) {
-	fprintf(logf, "\n\n");
+    if (p2c_logf) {
+	fprintf(p2c_logf, "\n\n");
 #if defined(unix) || defined(__unix)
-	fprintf(logf, "Total memory used: %ld bytes.\n", (long)sbrk(0));
+	fprintf(p2c_logf, "Total memory used: %ld bytes.\n", (long)sbrk(0));
 #endif
 	time(&ending_time);
-	fprintf(logf, "Processed %d source lines in %ld:%ld seconds.\n",
+	fprintf(p2c_logf, "Processed %d source lines in %ld:%ld seconds.\n",
 		inf_ltotal,
 		(ending_time - starting_time) / 60,
 		(ending_time - starting_time) % 60);
-	fprintf(logf, "\n\nTranslation completed on %s", ctime(&ending_time));
-	fclose(logf);
+	fprintf(p2c_logf, "\n\nTranslation completed on %s", ctime(&ending_time));
+	fclose(p2c_logf);
     }
 }
 
@@ -949,7 +951,7 @@
         setbuf(codef, NULL);      /* for debugging */
     outf = codef;
     outf_lnum = 1;
-    logf = NULL;
+    p2c_logf = NULL;
     if (verbose)
 	openlogfile();
     setup_complete = 0;
