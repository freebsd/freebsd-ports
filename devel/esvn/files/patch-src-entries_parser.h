--- src/entries_parser.h.orig	Sun Aug 15 16:14:54 2004
+++ src/entries_parser.h	Sun Aug 15 16:15:04 2004
@@ -20,6 +20,8 @@
 #include <qstring.h>
 #include <qdir.h>
 
+#include <sys/types.h>
+#include <time.h>
 #include <map>
 #include <iostream>
 
@@ -116,7 +118,7 @@
 #if (__FreeBSD__ || __NetBSD__ || __OpenBSD__ || ESVN_BSD)
 			time_t a; a = time(NULL);
 			struct tm bsd_hack = *localtime(&a);
-			result = ret.addSecs(-(bsd_hack.tm_gmtoff - bsd_hack.tm_isdst*3600) );
+			result = result.addSecs(-(bsd_hack.tm_gmtoff - bsd_hack.tm_isdst*3600) );
 #else
 			result = result.addSecs(-(timezone - daylight*3600));
 #endif
