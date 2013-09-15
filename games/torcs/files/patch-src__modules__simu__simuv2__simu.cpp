--- ./src/modules/simu/simuv2/simu.cpp.orig	2012-10-03 07:18:49.000000000 +0000
+++ ./src/modules/simu/simuv2/simu.cpp	2013-09-15 09:29:34.000000000 +0000
@@ -67,7 +67,6 @@
     if (isnan(car->ctrl->brakeCmd) || isinf(car->ctrl->brakeCmd)) car->ctrl->brakeCmd = 0;
     if (isnan(car->ctrl->clutchCmd) || isinf(car->ctrl->clutchCmd)) car->ctrl->clutchCmd = 0;
     if (isnan(car->ctrl->steer) || isinf(car->ctrl->steer)) car->ctrl->steer = 0;
-    if (isnan(car->ctrl->gear) || isinf(car->ctrl->gear)) car->ctrl->gear = 0;
 #endif
 
     /* When the car is broken try to send it on the track side */
