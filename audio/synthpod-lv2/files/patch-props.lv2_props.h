--- props.lv2/props.h.orig	2023-10-30 01:57:04 UTC
+++ props.lv2/props.h
@@ -25,6 +25,7 @@ extern "C" {
 #include <stdlib.h>
 #include <stdatomic.h>
 #include <stdio.h>
+#include <libgen.h>
 
 #include <lv2/lv2plug.in/ns/lv2core/lv2.h>
 #include <lv2/lv2plug.in/ns/ext/urid/urid.h>
