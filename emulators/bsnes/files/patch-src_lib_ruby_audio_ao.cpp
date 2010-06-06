--- src/lib/ruby/audio/ao.cpp.orig	2010-06-06 18:49:07.000000000 +0200
+++ src/lib/ruby/audio/ao.cpp	2010-06-06 18:49:30.000000000 +0200
@@ -51,6 +51,7 @@ public:
     driver_id = ao_default_driver_id(); //ao_driver_id((const char*)driver)
     if(driver_id < 0) return false;
 
+    memset(&driver_format, 0, sizeof(driver_format));
     driver_format.bits = 16;
     driver_format.channels = 2;
     driver_format.rate = settings.frequency;
