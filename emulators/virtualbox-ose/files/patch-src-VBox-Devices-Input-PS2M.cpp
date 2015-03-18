--- src/VBox/Devices/Input/PS2M.cpp.orig	2015-03-02 10:09:15.000000000 -0500
+++ src/VBox/Devices/Input/PS2M.cpp	2015-03-16 13:38:03.324517000 -0400
@@ -709,7 +709,7 @@
 static void ps2mReportAccumulatedEvents(PPS2M pThis)
 {
     uint8_t     val;
-    int8_t      dX, dY, dZ;
+    int         dX, dY, dZ;
 
     /* Clamp the accumulated delta values to the allowed range. */
     dX = RT_MIN(RT_MAX(pThis->iAccumX, -256), 255);
