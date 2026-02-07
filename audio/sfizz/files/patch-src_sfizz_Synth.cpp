--- src/sfizz/Synth.cpp.orig	2024-11-05 10:32:04 UTC
+++ src/sfizz/Synth.cpp
@@ -33,6 +33,7 @@
 #include "parser/Parser.h"
 #include <absl/algorithm/container.h>
 #include <absl/memory/memory.h>
+#include <absl/strings/str_cat.h>
 #include <absl/strings/str_replace.h>
 #include <absl/types/optional.h>
 #include <absl/types/span.h>
