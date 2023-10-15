--- src/vid_t3100e.c.orig	2020-12-01 19:49:05 UTC
+++ src/vid_t3100e.c
@@ -470,7 +470,7 @@ void t3100e_poll(void *p)
 
 	}
 	/* Switch between internal plasma and external CRT display. */
-	if (st_display_internal != -1 && st_display_internal != t3100e->internal)
+	if (st_display_internal != (uint8_t)-1 && st_display_internal != t3100e->internal)
 	{
 		t3100e->internal = st_display_internal;
                 t3100e_recalctimings(t3100e);
