--- calendar/libical/src/libical/icaltz-util.c.orig	2007-11-25 21:29:25.000000000 -0500
+++ calendar/libical/src/libical/icaltz-util.c	2008-01-07 20:24:12.000000000 -0500
@@ -23,6 +23,15 @@
 #include <string.h>
 #if defined(sun) && defined(__SVR4)
 #include <sys/byteorder.h>
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
+#define __BYTE_ORDER            _BYTE_ORDER
+#define __LITTLE_ENDIAN         _LITTLE_ENDIAN
+#define __BIG_ENDIAN            _BIG_ENDIAN
+
+#define bswap_16                bswap16
+#define bswap_32                bswap32
+#define bswap_64                bswap64
 #else
 #include <byteswap.h>
 #include <endian.h>
@@ -328,7 +337,10 @@ icaltzutil_fetch_timezone (const char *l
 		icalprop = icalproperty_new_tzname (types [zidx].zname);
 		icalcomponent_add_property (std_comp, icalprop);
 
-		trans = transitions [stdidx] + types [zidx].gmtoff;
+		if (num_trans)
+			trans = transitions [stdidx] + types [zidx].gmtoff;
+		else
+			trans = types [zidx].gmtoff;
 		icaltime = icaltime_from_timet (trans, 0);
 		dtstart = icaltime;
 		dtstart.year = 1970;
@@ -369,7 +381,10 @@ icaltzutil_fetch_timezone (const char *l
 		icalprop = icalproperty_new_tzname (types [zidx].zname);
 		icalcomponent_add_property (dst_comp, icalprop);
 
-		trans = transitions [dstidx] + types [zidx].gmtoff;
+		if (num_trans)
+			trans = transitions [dstidx] + types [zidx].gmtoff;
+		else
+			trans = types [zidx].gmtoff;
 		icaltime = icaltime_from_timet (trans, 0);
 		dtstart = icaltime;
 		dtstart.year = 1970;
