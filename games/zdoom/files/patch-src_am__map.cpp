--- src/am_map.cpp.orig	2016-02-22 02:11:13 UTC
+++ src/am_map.cpp
@@ -1692,9 +1692,9 @@ bool AM_clipMline (mline_t *ml, fline_t *fl)
 		TOP		=8
 	};
 
-	register int outcode1 = 0;
-	register int outcode2 = 0;
-	register int outside;
+	int outcode1 = 0;
+	int outcode2 = 0;
+	int outside;
 
 	fpoint_t tmp = { 0, 0 };
 	int dx;
