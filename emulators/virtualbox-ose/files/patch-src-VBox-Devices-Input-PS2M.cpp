--- src/VBox/Devices/Input/PS2M.cpp.orig	2015-03-02 10:09:15.000000000 -0500
+++ src/VBox/Devices/Input/PS2M.cpp	2015-03-12 18:44:38.787177000 -0400
@@ -712,8 +712,8 @@
     int8_t      dX, dY, dZ;
 
     /* Clamp the accumulated delta values to the allowed range. */
-    dX = RT_MIN(RT_MAX(pThis->iAccumX, -256), 255);
-    dY = RT_MIN(RT_MAX(pThis->iAccumY, -256), 255);
+    dX = RT_MIN(RT_MAX(pThis->iAccumX, -128), 127);
+    dY = RT_MIN(RT_MAX(pThis->iAccumY, -128), 127);
     dZ = RT_MIN(RT_MAX(pThis->iAccumZ, -8), 7);
 
     /* Start with the sync bit and buttons 1-3. */
