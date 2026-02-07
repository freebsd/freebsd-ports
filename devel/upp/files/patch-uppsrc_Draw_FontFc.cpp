# Draw: Workaround for backwards incompatibility of FT_Outline
# https://github.com/ultimatepp/ultimatepp/commit/68139e354876013046aac0d1699d7b61ce055d53

--- uppsrc/Draw/FontFc.cpp.orig	2020-10-16 9:28:02 UTC
+++ uppsrc/Draw/FontFc.cpp
@@ -290,10 +290,9 @@
 	FT_Vector   v_start;
 	FT_Vector*  point;
 	FT_Vector*  limit;
-	char*       tags;
 	int   n;         // index of contour in outline
-	char  tag;       // current point's state
 	int   first = 0; // index of first point in contour
+
 	for(n = 0; n < outline.n_contours; n++) {
 		int  last = outline.contours[n];
 		limit = outline.points + last;
@@ -301,8 +300,8 @@
 		v_last  = outline.points[last];
 		v_control = v_start;
 		point = outline.points + first;
-		tags  = outline.tags  + first;
-		tag   = FT_CURVE_TAG(tags[0]);
+		const auto *tags  = outline.tags  + first;
+		auto tag   = FT_CURVE_TAG(tags[0]);
 		if(tag == FT_CURVE_TAG_CUBIC) return false;
 		if(tag == FT_CURVE_TAG_CONIC) {
 			if(FT_CURVE_TAG(outline.tags[last]) == FT_CURVE_TAG_ON) {
