$FreeBSD$

--- ../../j2se/src/share/classes/java/util/TimeZone.java	8 Nov 2004 22:27:20 -0000	1.1.1.1
+++ ../../j2se/src/share/classes/java/util/TimeZone.java	5 Nov 2006 17:43:12 -0000
@@ -748,15 +748,13 @@
 	}
 	int gmtOffset =  (hours * 60 + num) * 60 * 1000;
 
+	zi = ZoneInfoFile.getCustomTimeZone(id, negative ? -gmtOffset : gmtOffset);
 	if (gmtOffset == 0) {
-	    zi = ZoneInfoFile.getZoneInfo(GMT_ID);
 	    if (negative) {
 		zi.setID("GMT-00:00");
 	    } else {
 		zi.setID("GMT+00:00");
 	    }
-	} else {
-	    zi = ZoneInfoFile.getCustomTimeZone(id, negative ? -gmtOffset : gmtOffset);
 	}
 	return zi;
     }
