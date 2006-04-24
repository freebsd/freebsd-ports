--- Eris/Calendar.cpp.orig	Fri Dec 30 20:07:55 2005
+++ Eris/Calendar.cpp	Mon Apr 24 07:13:42 2006
@@ -1,6 +1,12 @@
 #ifdef HAVE_CONFIG_H
 	#include "config.h"
 #endif
+#if defined(__FreeBSD__)
+#	include <osreldate.h>
+#	if __FreeBSD_version < 500000
+#		undef _XOPEN_SOURCE
+#	endif
+#endif
 
 #include <Eris/Calendar.h>
 #include <Eris/Avatar.h>
@@ -75,7 +81,11 @@
     // we don't have valid calendar data yet
     if (m_daysPerMonth == 0) return n;
     
+#if defined(__FreeBSD__) && __FreeBSD_version < 500000
+    n.m_seconds = rintf(m_avatar->getWorldTime());
+#else
     n.m_seconds = lrintf(m_avatar->getWorldTime());
+#endif
     
     n.m_minutes = n.m_seconds / m_secondsPerMinute;
     n.m_seconds -= (n.m_minutes * m_secondsPerMinute);
