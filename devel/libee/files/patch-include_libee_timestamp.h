--- include/libee/timestamp.h.orig	2011-06-21 14:30:23.982105039 -0500
+++ include/libee/timestamp.h	2011-06-21 14:30:49.970716777 -0500
@@ -29,6 +29,8 @@
 #ifndef LIBEE_TIMESTAMP_H_INCLUDED
 #define	LIBEE_TIMESTAMP_H_INCLUDED
 
+#include <time.h>
+
 /**
  * An object to represent a CEE/XML timestamp.
  * 
