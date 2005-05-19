--- cvslib/tzconvert.h.orig	Wed May 18 22:34:52 2005
+++ cvslib/tzconvert.h	Wed May 18 22:35:54 2005
@@ -73,6 +73,8 @@
 #ifndef TZCONVERT_H
 #define TZCONVERT_H
 
+#include <sys/time.h>
+
 #include "globals.h"
 
 inline QDateTime convertTimeZone(QDateTime &dateTime, bool hasDSTBug, bool toUTC)
