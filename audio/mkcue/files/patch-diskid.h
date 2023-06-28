--- diskid.h.orig	2023-06-27 06:22:10 UTC
+++ diskid.h
@@ -61,8 +61,8 @@ typedef	unsigned char byte;
 typedef unsigned long dword;
 
 typedef struct {
-    byte FirstTrack;         // The first track on CD : normally 1
-    byte LastTrack;          // The last track on CD: max number 99
+    ::byte FirstTrack;         // The first track on CD : normally 1
+    ::byte LastTrack;          // The last track on CD: max number 99
     
     dword FrameOffset[100];  // Track 2 is TrackFrameOffset[2] etc.
                              // Leadout Track will be TrackFrameOffset[0]
