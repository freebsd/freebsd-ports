--- src/esvn_utils.h.orig	Sat Nov 27 12:55:50 2004
+++ src/esvn_utils.h	Fri Dec 10 10:50:35 2004
@@ -5,6 +5,8 @@
 #include <qdir.h>
 #include <vector>
 
+#include <time.h>
+
 namespace EsvnUtils
 {
 	inline QDateTime UTC2Local(const QDateTime& utc)
