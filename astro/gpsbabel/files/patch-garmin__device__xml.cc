--- garmin_device_xml.cc.orig	2018-04-11 18:10:39 UTC
+++ garmin_device_xml.cc
@@ -41,7 +41,7 @@ jmp_buf gdx_jmp_buf;
 
 void type_s(xg_string args, const QXmlStreamAttributes*)
 {
-  type = args.compare("GPSData");
+  type = args.compare(QLatin1String("GPSData"));
 }
 
 void device_s(xg_string args, const QXmlStreamAttributes*)
