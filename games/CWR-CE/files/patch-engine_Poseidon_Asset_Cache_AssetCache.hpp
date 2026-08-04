--- engine/Poseidon/Asset/Cache/AssetCache.hpp.orig	2026-08-04 10:49:53 UTC
+++ engine/Poseidon/Asset/Cache/AssetCache.hpp
@@ -70,15 +70,15 @@ struct StringKeyHash
     // FNV-1a over lowercased bytes — case-insensitive hash matching the equality above.
     size_t operator()(const StringKey& k) const noexcept
     {
-        size_t h = 14695981039346656037ULL;
+        uint64_t h = 14695981039346656037ULL;
         for (char c : k.value)
         {
             const unsigned char u  = static_cast<unsigned char>(c);
             const unsigned char lc = (u >= 'A' && u <= 'Z') ? u + 32 : u;
-            h ^= static_cast<size_t>(lc);
+            h ^= static_cast<uint64_t>(lc);
             h *= 1099511628211ULL;
         }
-        return h;
+        return static_cast<size_t>(h);
     }
 };
 
