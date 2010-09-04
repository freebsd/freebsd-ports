--- bsnes/snes/system/serialization.cpp.orig	2010-09-02 13:16:20.000000000 +0200
+++ bsnes/snes/system/serialization.cpp	2010-09-02 13:23:12.000000000 +0200
@@ -7,7 +7,7 @@
   char profile[16], description[512];
   memset(&profile, 0, sizeof profile);
   memset(&description, 0, sizeof description);
-  strlcpy(profile, Info::Profile, sizeof profile);
+  nall::strlcpy(profile, Info::Profile, sizeof profile);
 
   s.integer(signature);
   s.integer(version);
