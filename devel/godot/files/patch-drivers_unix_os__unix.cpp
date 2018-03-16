--- drivers/unix/os_unix.cpp.orig	2018-02-01 19:27:25 UTC
+++ drivers/unix/os_unix.cpp
@@ -235,7 +235,7 @@ OS::TimeZoneInfo OS_Unix::get_time_zone_
 
 void OS_Unix::delay_usec(uint32_t p_usec) const {
 
-	struct timespec rem = { p_usec / 1000000, (p_usec % 1000000) * 1000 };
+	struct timespec rem = { time_t(p_usec) / 1000000, (long(p_usec) % 1000000) * 1000 };
 	while (nanosleep(&rem, &rem) == EINTR) {
 	}
 }
