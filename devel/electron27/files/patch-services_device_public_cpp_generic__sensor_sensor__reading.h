--- services/device/public/cpp/generic_sensor/sensor_reading.h.orig	2023-10-19 19:58:30 UTC
+++ services/device/public/cpp/generic_sensor/sensor_reading.h
@@ -5,6 +5,8 @@
 #ifndef SERVICES_DEVICE_PUBLIC_CPP_GENERIC_SENSOR_SENSOR_READING_H_
 #define SERVICES_DEVICE_PUBLIC_CPP_GENERIC_SENSOR_SENSOR_READING_H_
 
+#include <cstdint>
+
 #include <type_traits>
 
 namespace device {
