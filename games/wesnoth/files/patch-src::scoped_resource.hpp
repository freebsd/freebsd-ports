--- src/scoped_resource.hpp.orig	Sat Jul  3 16:23:45 2004
+++ src/scoped_resource.hpp	Sat Jul  3 16:24:35 2004
@@ -13,6 +13,8 @@
 #ifndef SCOPED_RESOURCE_H_INCLUDED
 #define SCOPED_RESOURCE_H_INCLUDED
 
+#include <cstdio>
+
 /**
 * The util namespace should take all classes which are of a generic type,
 * used to perform common tasks which are not BibleTime-specific. See
