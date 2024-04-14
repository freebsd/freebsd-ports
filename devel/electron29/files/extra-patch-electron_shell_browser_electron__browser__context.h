--- electron/shell/browser/electron_browser_context.h.orig	2024-01-23 19:02:02 UTC
+++ electron/shell/browser/electron_browser_context.h
@@ -8,7 +8,6 @@
 #include <map>
 #include <memory>
 #include <string>
-#include <string_view>
 #include <variant>
 #include <vector>
 #include "base/memory/raw_ptr.h"
@@ -79,22 +78,41 @@ class ElectronBrowserContext : public content::Browser
 
   // partition_id => browser_context
   struct PartitionKey {
-    PartitionKey(const std::string_view partition, bool in_memory)
-        : type_{Type::Partition}, location_{partition}, in_memory_{in_memory} {}
+    enum class KeyType { Partition, FilePath };
+    std::string location;
+    bool in_memory;
+    KeyType partition_type;
 
+    PartitionKey(const std::string& partition, bool in_memory)
+        : location(partition),
+          in_memory(in_memory),
+          partition_type(KeyType::Partition) {}
     explicit PartitionKey(const base::FilePath& file_path)
-        : type_{Type::Path},
-          location_{file_path.AsUTF8Unsafe()},
-          in_memory_{false} {}
+        : location(file_path.AsUTF8Unsafe()),
+          in_memory(false),
+          partition_type(KeyType::FilePath) {}
 
-    friend auto operator<=>(const PartitionKey&, const PartitionKey&) = default;
+    bool operator<(const PartitionKey& other) const {
+      if (partition_type == KeyType::Partition) {
+        if (location == other.location)
+          return in_memory < other.in_memory;
+        return location < other.location;
+      } else {
+        if (location == other.location)
+          return false;
+        return location < other.location;
+      }
+    }
 
-   private:
-    enum class Type { Partition, Path };
-
-    Type type_;
-    std::string location_;
-    bool in_memory_;
+    bool operator==(const PartitionKey& other) const {
+      if (partition_type == KeyType::Partition) {
+        return (location == other.location) && (in_memory < other.in_memory);
+      } else {
+        if (location == other.location)
+          return true;
+        return false;
+      }
+    }
   };
 
   using BrowserContextMap =
