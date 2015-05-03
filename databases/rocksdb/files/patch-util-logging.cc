--- util/logging.cc.orig	2015-03-25 21:40:41 UTC
+++ util/logging.cc
@@ -35,10 +35,10 @@ int AppendHumanMicros(uint64_t micros, c
   } else if (micros < 10000000) {
     return snprintf(output, len, "%.3lf ms",
                     static_cast<double>(micros) / 1000);
-  } else if (micros < 1000000l * 60) {
+  } else if (micros < 1000000LL * 60) {
     return snprintf(output, len, "%.3lf sec",
                     static_cast<double>(micros) / 1000000);
-  } else if (micros < 1000000l * 60 * 60) {
+  } else if (micros < 1000000LL * 60 * 60) {
     return snprintf(output, len, "%02" PRIu64 ":%05.3f M:S",
         micros / 1000000 / 60,
         static_cast<double>(micros % 60000000) / 1000000);
