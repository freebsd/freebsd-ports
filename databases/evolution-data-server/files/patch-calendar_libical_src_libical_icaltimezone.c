Index: calendar/libical/src/libical/icaltimezone.c
===================================================================
--- calendar/libical/src/libical/icaltimezone.c	(révision 593)
+++ calendar/libical/src/libical/icaltimezone.c	(copie de travail)
@@ -1433,7 +1433,7 @@
 	
 	z_offset = get_offset(zone);
 
-	if (z_offset == offset && !strcmp(tzname, zone->tznames))
+	if (z_offset == offset && zone->tznames && !strcmp(tzname, zone->tznames))
 	    return zone;
     }
     
