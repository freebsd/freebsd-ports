--- src/vehicle.h.orig	2023-04-13 00:36:07 UTC
+++ src/vehicle.h
@@ -65,7 +65,7 @@ typedef struct _GrEngineData	GrEngineData;
 typedef struct _GrLapHistory	GrLapHistory;
 typedef struct _GrVehicleData	GrVehicleData;
 
-struct _GrBreakData {
+extern struct _GrBreakData {
   GrRef ref;
 
   /* constants */
