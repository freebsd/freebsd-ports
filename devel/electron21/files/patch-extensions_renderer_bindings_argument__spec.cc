--- extensions/renderer/bindings/argument_spec.cc.orig	2022-09-24 10:57:32 UTC
+++ extensions/renderer/bindings/argument_spec.cc
@@ -16,6 +16,8 @@
 #include "gin/data_object_builder.h"
 #include "gin/dictionary.h"
 
+#include <cmath>
+
 namespace extensions {
 
 namespace {
