--- ext/standard/datetime.c.orig	Tue Aug 26 11:06:04 2003
+++ ext/standard/datetime.c	Tue Aug 26 11:07:27 2003
@@ -116,7 +116,13 @@
 	/* Let DST be unknown. mktime() should compute the right value
 	** and behave correctly. Unless the user overrides this.
 	*/
-	ta->tm_isdst = -1;
+	if (gm) {
+		ta->tm_isdst = 0;
+		is_dst = 0;
+	} else {
+		ta->tm_isdst = -1;
+		is_dst = -1;
+	}
 
 	/*
 	** Now change date values with supplied parameters.
