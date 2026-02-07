--- engine/src/segment/Segment.cpp.orig	2008-08-21 14:24:32 UTC
+++ engine/src/segment/Segment.cpp
@@ -433,7 +433,7 @@ void Segment::InitWhiteSpaceSegment(int nNewDepth)
 /*----------------------------------------------------------------------------------------------
 	Basic copy method.
 ----------------------------------------------------------------------------------------------*/
-Segment::Segment(Segment & seg)
+Segment::Segment(const Segment & seg)
 {
 	int islout;
 
