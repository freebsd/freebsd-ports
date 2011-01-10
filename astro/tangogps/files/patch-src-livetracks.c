--- src/livetracks.c	Sat Jul 10 06:54:31 2010 -0700
+++ src/livetracks.c	Fri Jul 23 06:17:04 2010 -0700
@@ -65,9 +65,9 @@
 		tp = list->data;
 		
 		if(tp->time > time_last_update)
-			g_string_append_printf(string, "::%d:%f:%f:%.1f:%.1f:%.0f:%.0f:%d%%0A",
+			g_string_append_printf(string, "::%d:%f:%f:%.1f:%.1f:%.0f:%.0f:%%0A",
 					tp->time, tp->lat_deg, tp->lon_deg,
-					tp->alt, tp->speed, tp->head, tp->hdop, tp->heart);
+					tp->alt, tp->speed, tp->head, tp->hdop);
 	}
 
 	
