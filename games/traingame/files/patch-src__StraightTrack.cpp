--- ./src/StraightTrack.cpp.orig	2013-12-21 13:18:27.000000000 +0100
+++ ./src/StraightTrack.cpp	2014-03-15 19:53:57.938221605 +0100
@@ -259,5 +259,5 @@
       throw runtime_error("Illegal straight track direction: "
          + lexical_cast<string>(a_direction));
 
-   return ITrackSegmentPtr(new StraightTrack(real_dir));
+   return ITrackSegmentPtr(static_cast<ITrackSegment *>(new StraightTrack(real_dir)));
 }
