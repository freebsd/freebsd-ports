--- input/drivers/udev_input.c.orig	2025-05-01 00:17:50 UTC
+++ input/drivers/udev_input.c
@@ -71,7 +71,9 @@
 
 #include "../input_keymaps.h"
 
+#ifdef __linux__
 #include "../common/linux_common.h"
+#endif
 
 #include "../../configuration.h"
 #include "../../retroarch.h"
@@ -570,7 +572,9 @@ typedef struct udev_input
    bool xkb_handling;
 #endif
 
+#ifdef __linux__
    linux_illuminance_sensor_t *illuminance_sensor;
+#endif
 } udev_input_t;
 
 #ifdef UDEV_XKB_HANDLING
@@ -3952,7 +3956,9 @@ static void udev_input_free(void *data)
 
    udev_input_kb_free(udev);
 
+#ifdef __linux__
    linux_close_illuminance_sensor(udev->illuminance_sensor);
+#endif
 
    free(udev);
 }
@@ -3968,13 +3974,16 @@ static bool udev_set_sensor_state(void *data, unsigned
    {
       case RETRO_SENSOR_ILLUMINANCE_DISABLE:
          /* If already disabled, then do nothing */
+#ifdef __linux__
          linux_close_illuminance_sensor(udev->illuminance_sensor); /* noop if NULL */
          udev->illuminance_sensor = NULL;
+#endif
       case RETRO_SENSOR_GYROSCOPE_DISABLE:
       case RETRO_SENSOR_ACCELEROMETER_DISABLE:
          /** Unimplemented sensor actions that probably shouldn't fail */
          return true;
 
+#ifdef __linux__
       case RETRO_SENSOR_ILLUMINANCE_ENABLE:
          if (udev->illuminance_sensor)
             /* If we already have a sensor, just set the rate */
@@ -3983,6 +3992,7 @@ static bool udev_set_sensor_state(void *data, unsigned
             udev->illuminance_sensor = linux_open_illuminance_sensor(rate);
 
          return udev->illuminance_sensor != NULL;
+#endif
       default:
          break;
    }
@@ -3992,6 +4002,7 @@ static float udev_get_sensor_input(void *data, unsigne
 
 static float udev_get_sensor_input(void *data, unsigned port, unsigned id)
 {
+#ifdef __linux__
    udev_input_t *udev = (udev_input_t*)data;
 
    if (!udev)
@@ -4005,6 +4016,7 @@ static float udev_get_sensor_input(void *data, unsigne
       default:
          break;
    }
+#endif
 
    return 0.0f;
 }
