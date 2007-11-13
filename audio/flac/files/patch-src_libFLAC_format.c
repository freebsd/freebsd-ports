
$FreeBSD$

--- src/libFLAC/format.c.orig
+++ src/libFLAC/format.c
@@ -38,6 +38,7 @@
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
+#include "share/alloc.h"
 
 #ifdef min
 #undef min
@@ -463,9 +464,9 @@
 	FLAC__ASSERT(object->capacity_by_order > 0 || (0 == object->parameters && 0 == object->raw_bits));
 
 	if(object->capacity_by_order < max_partition_order) {
-		if(0 == (object->parameters = (unsigned*)realloc(object->parameters, sizeof(unsigned)*(1 << max_partition_order))))
+		if(0 == (object->parameters = (unsigned*)safe_realloc_mul_2op_(object->parameters, sizeof(unsigned), /*times*/(1 << max_partition_order))))
 			return false;
-		if(0 == (object->raw_bits = (unsigned*)realloc(object->raw_bits, sizeof(unsigned)*(1 << max_partition_order))))
+		if(0 == (object->raw_bits = (unsigned*)safe_realloc_mul_2op_(object->raw_bits, sizeof(unsigned), /*times*/(1 << max_partition_order))))
 			return false;
 		object->capacity_by_order = max_partition_order;
 	}
