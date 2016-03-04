--- trans.c.orig	2015-10-02 17:52:53 UTC
+++ trans.c
@@ -23,6 +23,8 @@ the Free Software Foundation, Inc., 675 
 #include "trans.h"
 
 #include <time.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 
 
@@ -575,7 +577,7 @@ extern char *getenv PP((char *));
 # endif
 #endif
 
-Static long starting_time;
+Static time_t starting_time;
 
 Static void openlogfile()
 {
@@ -608,7 +610,7 @@ Static void openlogfile()
 
 void closelogfile()
 {
-    long ending_time;
+    time_t ending_time;
 
     if (logfile) {
 	fprintf(logfile, "\n\n");
