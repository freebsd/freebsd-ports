--- src/util/VarSize.hxx.orig	2015-03-17 11:18:04 UTC
+++ src/util/VarSize.hxx
@@ -36,6 +36,7 @@
 #include <type_traits>
 #include <utility>
 #include <new>
+#include <cstdlib>
 
 /**
  * Allocate and construct a variable-size object.  That is useful for
