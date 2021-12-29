--- src/obstack.c.orig	2021-12-28 19:08:19 UTC
+++ src/obstack.c
@@ -29,7 +29,7 @@
 # include "obstack.h"
 #endif
 
-#include <stdint-gcc.h>
+//#include <stdint-gcc.h>
 
 /* NOTE BEFORE MODIFYING THIS FILE: This version number must be
    incremented whenever callers compiled using an old obstack.h can no
