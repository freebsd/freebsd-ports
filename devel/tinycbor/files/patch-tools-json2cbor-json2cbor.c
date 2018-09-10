--- tools/json2cbor/json2cbor.c.orig	2018-09-09 05:33:57 UTC
+++ tools/json2cbor/json2cbor.c
@@ -25,6 +25,7 @@
 #define _POSIX_C_SOURCE 200809L
 #define _GNU_SOURCE
 #include "cbor.h"
+#include "cborinternal_p.h"
 #include "compilersupport_p.h"
 
 #include <cjson/cJSON.h>
