--- src/celengine/star.h.orig	Tue May 22 12:51:07 2007
+++ src/celengine/star.h	Tue May 22 12:51:22 2007
@@ -30,7 +30,7 @@
     // orbits and StarDetails objects.  Currently, it's assumed that they
     // have lifetimes that continue until program termination.
  public:
-    StarDetails::StarDetails();
+    StarDetails();
 
     inline float getRadius() const;
     inline float getTemperature() const;
