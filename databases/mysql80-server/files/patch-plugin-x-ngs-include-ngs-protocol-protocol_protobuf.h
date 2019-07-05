--- plugin/x/ngs/include/ngs/protocol/protocol_protobuf.h.orig	2019-04-13 11:46:31 UTC
+++ plugin/x/ngs/include/ngs/protocol/protocol_protobuf.h
@@ -38,7 +38,6 @@
 #include <google/protobuf/repeated_field.h>
 #include <google/protobuf/text_format.h>
 #include <google/protobuf/wire_format_lite.h>
-#include <google/protobuf/wire_format_lite_inl.h>
 
 #ifdef USE_MYSQLX_FULL_PROTO
 #include "plugin/x/generated/protobuf/mysqlx.pb.h"
