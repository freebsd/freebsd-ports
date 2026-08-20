--- fdbserver/tester.actor.cpp.orig	2025-07-02 21:14:39 UTC
+++ fdbserver/tester.actor.cpp
@@ -31,6 +31,8 @@
 #include <map>
 #include <streambuf>
 #include <numeric>
+
+#include <fmt/ranges.h>
 #include <toml.hpp>
 
 #include "flow/ActorCollection.h"
