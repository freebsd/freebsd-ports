--- src/job_importplaylist.cpp.orig	2007-01-07 06:51:11.000000000 +0900
+++ src/job_importplaylist.cpp	2008-06-04 02:01:55.000000000 +0900
@@ -9,6 +9,7 @@
 #include <qstringlist.h>
 #include <qregexp.h>
 #include <qfile.h>
+#include <qdir.h>
 #include <qfileinfo.h>
 
 #ifdef EMBEDDED
