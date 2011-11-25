

Patch attached with submission follows:

--- lib/refcounted.h.orig	2010-06-03 20:59:23.000000000 +0300
+++ lib/refcounted.h	2011-11-08 15:45:51.024492252 +0200
@@ -29,6 +29,7 @@
 #define MYSQLPP_REFCOUNTED_H
 
 #include <memory>
+#include <cstddef>
 
 namespace mysqlpp {
 


