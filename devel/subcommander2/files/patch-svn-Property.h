--- svn/Property.h.orig	2006-01-17 15:40:34.000000000 -0500
+++ svn/Property.h	2009-04-06 14:40:42.000000000 -0400
@@ -17,8 +17,7 @@
 #include <vector>
 
 // svn
-struct svn_prop_t;
-
+#include <svn_props.h>
 
 namespace svn
 {
