--- lib/ofx_utilities.cpp.orig	2007-10-27 14:15:58.000000000 +0200
+++ lib/ofx_utilities.cpp	2009-11-08 01:02:47.000000000 +0100
@@ -16,6 +16,7 @@
  *                                                                         *
  ***************************************************************************/
 #include <config.h>
+#include <locale.h>
 #include <iostream>
 #include <assert.h>
 
@@ -113,6 +114,9 @@
   char time_zone_specified = false;
 
   time_t temptime;
+
+  bzero(&time, sizeof(time));
+
   std::time(&temptime);
   local_offset = difftime(mktime(localtime(&temptime)), mktime(gmtime(&temptime)));
   
