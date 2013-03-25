--- simtypes.h.orig
+++ simtypes.h
@@ -17,6 +17,9 @@
 #	define ALLOCA(type, name, count) type* name = static_cast<type*>(alloca(sizeof(type) * (count)))
 #
 # define inline _inline
+#elif defined __clang__
+#	include <stdlib.h>
+#	define ALLOCA(type, name, count) type* name = static_cast<type*>(alloca(sizeof(type) * (count)))
 #else
 #	define ALLOCA(type, name, count) type name[count]
 #endif
