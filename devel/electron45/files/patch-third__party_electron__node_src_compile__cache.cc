--- third_party/electron_node/src/compile_cache.cc.orig	2026-10-20 17:54:51 UTC
+++ third_party/electron_node/src/compile_cache.cc
@@ -44,16 +44,23 @@ uint32_t GetHash(const char* data, size_t size) {
   return crc32(crc, reinterpret_cast<const Bytef*>(data), size);
 }
 
-std::string GetCacheVersionTag() {
+std::string GetCacheVersionTag(EnableOption option) {
+  std::string tag = std::string(NODE_VERSION) + '-' + std::string(NODE_ARCH) +
+                    '-' + Uint32ToHex(ScriptCompiler::CachedDataVersionTag());
+#ifdef NODE_IMPLEMENTS_POSIX_CREDENTIALS
   // On platforms where uids are available, use different folders for
   // different users to avoid cache miss due to permission incompatibility.
   // On platforms where uids are not available, bare with the cache miss.
   // This should be fine on Windows, as there local directories tend to be
   // user-specific.
-  std::string tag = std::string(NODE_VERSION) + '-' + std::string(NODE_ARCH) +
-                    '-' + Uint32ToHex(ScriptCompiler::CachedDataVersionTag());
-#ifdef NODE_IMPLEMENTS_POSIX_CREDENTIALS
-  tag += '-' + std::to_string(getuid());
+  // A portable cache is meant to be reused wherever the same layout is
+  // found, including by other users (e.g. a cache generated at build time
+  // and shipped read-only with an application), so it is not split by uid:
+  // a user who cannot write to it still reads it, and a failed write is
+  // only a cache miss.
+  if (option != EnableOption::PORTABLE) {
+    tag += '-' + std::to_string(getuid());
+  }
 #endif
   return tag;
 }
@@ -538,11 +545,12 @@ CompileCacheHandler::CompileCacheHandler(Environment* 
 // Directory structure:
 // - Compile cache directory (from NODE_COMPILE_CACHE)
 //   - $NODE_VERSION-$ARCH-$CACHE_DATA_VERSION_TAG-$UID
+//     ($UID is omitted for a portable cache)
 //     - $FILENAME_AND_MODULE_TYPE_HASH.cache: a hash of filename + module type
 CompileCacheEnableResult CompileCacheHandler::Enable(Environment* env,
                                                      const std::string& dir,
                                                      EnableOption option) {
-  std::string cache_tag = GetCacheVersionTag();
+  std::string cache_tag = GetCacheVersionTag(option);
   std::string absolute_cache_dir_base = PathResolve(env, {dir});
   std::string cache_dir_with_tag =
       absolute_cache_dir_base + kPathSeparator + cache_tag;
