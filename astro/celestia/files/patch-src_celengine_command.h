--- src/celengine/command.h.orig	Tue May 22 13:29:01 2007
+++ src/celengine/command.h	Tue May 22 13:29:30 2007
@@ -94,7 +94,7 @@
 class CommandGotoLongLat : public InstantaneousCommand
 {
  public:
-    CommandGotoLongLat::CommandGotoLongLat(double t,
+    CommandGotoLongLat(double t,
                                            double dist,
                                            float _longitude, float _latitude,
                                            Vec3f _up);
