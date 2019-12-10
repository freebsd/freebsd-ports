https://github.com/mawww/kakoune/pull/3249

--- src/json_ui.cc.orig	2019-12-10 17:07:00 UTC
+++ src/json_ui.cc
@@ -9,6 +9,7 @@
 #include "ranges.hh"
 #include "string_utils.hh"
 
+#include <cstdio>
 #include <utility>
 
 #include <unistd.h>
