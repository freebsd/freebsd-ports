--- test/test-libevdev-events.c.orig	2017-05-04 00:37:30 UTC
+++ test/test-libevdev-events.c
@@ -1057,7 +1057,7 @@ START_TEST(test_syn_delta_late_sync)
 	} while (rc >= 0);
 
 	/* force enough events to trigger a SYN_DROPPED */
-	for (i = 0; i < 100; i++) {
+	for (i = 0; i < 200; i++) {
 		uinput_device_event(uidev, EV_ABS, ABS_X, 100 + i);
 		uinput_device_event(uidev, EV_ABS, ABS_Y, 500 + i);
 		uinput_device_event(uidev, EV_ABS, ABS_MT_POSITION_X, 100 + i);
@@ -1152,7 +1152,7 @@ START_TEST(test_syn_delta_late_sync)
 	} while (rc >= 0);
 
 	/* force enough events to trigger a SYN_DROPPED */
-	for (i = 0; i < 100; i++) {
+	for (i = 0; i < 200; i++) {
 		uinput_device_event(uidev, EV_ABS, ABS_X, 100 + i);
 		uinput_device_event(uidev, EV_ABS, ABS_Y, 500 + i);
 		uinput_device_event(uidev, EV_ABS, ABS_MT_POSITION_X, 100 + i);
