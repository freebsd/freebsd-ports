--- gcc/config/avr/driver-avr.c.orig	2013-03-14 16:26:36.000000000 +0100
+++ gcc/config/avr/driver-avr.c	2013-03-14 16:28:52.000000000 +0100
@@ -55,7 +55,7 @@
 avr_device_to_arch (int argc, const char **argv)
 {
   if (0 == argc)
-    return;
+    return NULL;
 
   avr_set_current_device (argv[0]);
 
@@ -71,7 +71,7 @@
   char data_section_start_str[16];
 
   if (0 == argc)
-    return;  
+    return NULL;  
 
   avr_set_current_device (argv[0]);
   
@@ -93,7 +93,7 @@
 avr_device_to_startfiles (int argc, const char **argv)
 {
   if (0 == argc)
-    return;
+    return NULL;
 
   avr_set_current_device (argv[0]);
 
@@ -106,7 +106,7 @@
 avr_device_to_devicelib (int argc, const char **argv)
 {
   if (0 == argc)
-    return;
+    return NULL;
 
   avr_set_current_device (argv[0]);
 
