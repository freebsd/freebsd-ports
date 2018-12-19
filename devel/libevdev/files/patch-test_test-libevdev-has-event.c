--- test/test-libevdev-has-event.c.orig	2017-05-04 00:37:30 UTC
+++ test/test-libevdev-has-event.c
@@ -116,6 +116,13 @@ START_TEST(test_event_codes)
 			evbit++;
 			continue;
 		}
+#ifdef __FreeBSD__
+		/* Force feedback events are not supported by FreeBSD */
+		if (*evbit == EV_FF) {
+			evbit++;
+			continue;
+		}
+#endif
 
 		max = libevdev_event_type_get_max(*evbit);
 
