--- mytreeview.cc.orig	2019-03-29 02:24:01 UTC
+++ mytreeview.cc
@@ -29,23 +29,7 @@
 
 #include "mytreeview.h"
 
-static const char *ctl_typename[CTLTYPE+1] = {
-    [CTLTYPE_INT] = "integer",
-    [CTLTYPE_UINT] = "unsigned integer",
-    [CTLTYPE_LONG] = "long integer",
-    [CTLTYPE_ULONG] = "unsigned long",
-    [CTLTYPE_U8] = "uint8_t",
-    [CTLTYPE_U16] = "uint16_t",
-    [CTLTYPE_U32] = "uint32_t",
-    [CTLTYPE_U64] = "uint64_t",
-    [CTLTYPE_S8] = "int8_t",
-    [CTLTYPE_S16] = "int16_t",
-    [CTLTYPE_S32] = "int32_t",
-    [CTLTYPE_S64] = "int64_t",
-    [CTLTYPE_NODE] = "node",
-    [CTLTYPE_STRING] = "string",
-    [CTLTYPE_OPAQUE] = "opaque",
-};
+static const char *ctl_typename[CTLTYPE+1] = { "ZEROUNUSED", "node", "integer", "string", "int64_t", "opaque", "unsigned integer", "long integer", "unsigned long", "uint64_t", "uint8_t", "uint16_t", "int8_t","int16_t", "int32_t", "uint32_t" };
 
 /* Public Methods */
 
