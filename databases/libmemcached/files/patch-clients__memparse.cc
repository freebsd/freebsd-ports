--- clients/memparse.cc.orig	2011-03-30 00:50:27.000000000 +0800
+++ clients/memparse.cc	2011-05-23 20:36:12.000000000 +0800
@@ -37,6 +37,7 @@
 
 #include <config.h>
 
+#include <string.h>
 #include <iostream>
 
 #include <libmemcached/memcached.h>
