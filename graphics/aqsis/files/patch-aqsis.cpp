--- aqsis/aqsis.cpp.orig	Fri Sep 13 13:07:03 2002
+++ aqsis/aqsis.cpp	Fri Sep 13 13:07:56 2002
@@ -66,8 +66,8 @@
  */
 RtVoid PrintProgress( RtFloat percent )
 {
-static long tick=0;
-long now;
+static time_t tick=0;
+time_t now;
     
 	if (tick == 0) 
         {
