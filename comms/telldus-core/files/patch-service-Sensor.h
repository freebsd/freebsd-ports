--- service/Sensor.h
+++ service/Sensor.h
@@ -8,6 +8,9 @@
 #define TELLDUS_CORE_SERVICE_SENSOR_H_
 
 #include <string>
+#ifdef __FreeBSD__
+#include <ctime>
+#endif
 #include "common/Mutex.h"
 
 class Sensor : public TelldusCore::Mutex {
