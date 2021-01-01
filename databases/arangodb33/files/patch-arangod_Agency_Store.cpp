--- arangod/Agency/Store.cpp.orig	2018-01-05 13:56:52 UTC
+++ arangod/Agency/Store.cpp
@@ -603,7 +603,7 @@ void Store::dumpToBuilder(Builder& build
       auto ts = std::chrono::duration_cast<std::chrono::seconds>(
                     i.first.time_since_epoch())
                     .count();
-      builder.add(i.second, VPackValue(ts));
+      builder.add(i.second, VPackValue((int64_t)ts));
     }
   }
   {
