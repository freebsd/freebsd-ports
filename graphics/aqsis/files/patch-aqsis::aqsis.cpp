--- aqsis/aqsis.cpp.orig	Sun Feb 16 23:36:02 2003
+++ aqsis/aqsis.cpp	Sat Apr 19 22:56:01 2003
@@ -82,8 +82,8 @@
 		return ;
 	}
 
-	static long tick = 0;
-	long now;
+	static time_t tick = 0;
+	time_t now;
 
 	if ( tick == 0 )
 		time( &tick );
