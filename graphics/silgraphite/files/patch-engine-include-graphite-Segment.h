--- engine/include/graphite/Segment.h.orig	2009-01-29 08:33:19 UTC
+++ engine/include/graphite/Segment.h
@@ -64,7 +64,7 @@ class Segment (public)
 	virtual ~Segment();
 
 	// Basic copy constructor:
-	Segment(Segment & seg);
+	Segment(const Segment & seg);
 
 	// For making modified copies of segments:
 	static Segment * LineContextSegment(Segment & seg, bool fStartLine, bool fEndLine);
