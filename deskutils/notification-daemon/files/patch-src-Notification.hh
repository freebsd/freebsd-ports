--- src/Notification.hh.orig	Thu Jul 28 10:50:44 2005
+++ src/Notification.hh	Wed Aug 31 23:14:48 2005
@@ -31,6 +31,7 @@
 #include "Hint.hh"
 #include "Image.hh"
 
+#include <sys/types.h>
 
 /*
  * This class represents a notification. It's a class rather than a struct
