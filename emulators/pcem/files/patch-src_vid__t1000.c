--- src/vid_t1000.c.orig	2020-12-01 19:49:05 UTC
+++ src/vid_t1000.c
@@ -436,7 +436,7 @@ static void t1000_poll(void *p)
                 else    mem_mapping_disable(&t1000->mapping);
 	}
 	/* Switch between internal plasma and external CRT display. */
-	if (st_display_internal != -1 && st_display_internal != t1000->internal)
+	if (st_display_internal != (uint8_t)-1 && st_display_internal != t1000->internal)
 	{
 		t1000->internal = st_display_internal;
                 t1000_recalctimings(t1000);
