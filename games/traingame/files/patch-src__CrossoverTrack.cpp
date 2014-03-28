--- ./src/CrossoverTrack.cpp.orig	2013-12-21 13:18:27.000000000 +0100
+++ ./src/CrossoverTrack.cpp	2014-03-15 19:51:31.988732983 +0100
@@ -215,5 +215,5 @@
 
 ITrackSegmentPtr make_crossover_track()
 {
-   return ITrackSegmentPtr(new CrossoverTrack);
+   return ITrackSegmentPtr(static_cast<ITrackSegment *>(new CrossoverTrack));
 }
