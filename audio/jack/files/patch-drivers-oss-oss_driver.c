--- drivers/oss/oss_driver.c.orig
+++ drivers/oss/oss_driver.c
@@ -23,6 +23,7 @@
 
 #include <config.h>
 
+#define __BSD_VISIBLE	1
 #ifdef USE_BARRIER
 /*
  * POSIX conformance level should be globally defined somewhere, possibly
@@ -181,7 +182,9 @@ static void set_period_size (oss_driver_
 		((double) driver->period_size /
 		(double) driver->sample_rate) * 1e6;
 	driver->last_wait_ust = 0;
-	driver->last_periodtime = driver->engine->get_microseconds();
+	driver->last_periodtime = driver->engine ?
+		driver->engine->get_microseconds() :
+		jack_get_microseconds();
 	driver->next_periodtime = 0;
 	driver->iodelay = 0.0F;
 }
@@ -189,7 +192,9 @@ static void set_period_size (oss_driver_
 
 static inline void update_times (oss_driver_t *driver)
 {
-	driver->last_periodtime = driver->engine->get_microseconds();
+	driver->last_periodtime = driver->engine ?
+		driver->engine->get_microseconds() :
+		jack_get_microseconds();
 	if (driver->next_periodtime > 0)
 	{
 		driver->iodelay = (float)
@@ -759,7 +764,9 @@ static int oss_driver_start (oss_driver_
 	if (driver->threads & 1) sem_post(&driver->sem_start);
 	if (driver->threads & 2) sem_post(&driver->sem_start);
 
-	driver->last_periodtime = driver->engine->get_microseconds();
+	driver->last_periodtime = driver->engine ?
+		driver->engine->get_microseconds() :
+		jack_get_microseconds();
 	driver->next_periodtime = 0;
 	driver->iodelay = 0.0F;
 
