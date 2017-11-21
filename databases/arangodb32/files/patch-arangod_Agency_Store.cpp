--- arangod/Agency/Store.cpp.orig	2017-11-15 11:23:07 UTC
+++ arangod/Agency/Store.cpp
@@ -601,7 +601,7 @@ void Store::dumpToBuilder(Builder& build
       auto ts = std::chrono::duration_cast<std::chrono::seconds>(
                     i.first.time_since_epoch())
                     .count();
-      builder.add(i.second, VPackValue(ts));
+      builder.add(i.second, VPackValue((int64_t)ts));
     }
   }
   {
