--- contrib/rocksdb/util/crc32c.cc.orig	2021-07-21 16:35:20.404459000 +0200
+++ contrib/rocksdb/util/crc32c.cc	2021-07-22 09:48:10.980923000 +0200
@@ -41,7 +41,7 @@
 
 #endif
 
-#if defined(__linux__) && defined(HAVE_ARM64_CRC)
+#if (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
 bool pmull_runtime_flag = false;
 #endif
 
@@ -474,7 +474,7 @@ static bool isAltiVec() {
 }
 #endif
 
-#if defined(__linux__) && defined(HAVE_ARM64_CRC)
+#if (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
 uint32_t ExtendARMImpl(uint32_t crc, const char *buf, size_t size) {
   return crc32c_arm64(crc, (const unsigned char *)buf, size);
 }
@@ -494,7 +494,7 @@ std::string IsFastCrc32Supported() {
   has_fast_crc = false;
   arch = "PPC";
 #endif
-#elif defined(__linux__) && defined(HAVE_ARM64_CRC)
+#elif (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
   if (crc32c_runtime_check()) {
     has_fast_crc = true;
     arch = "Arm64";
@@ -1227,7 +1227,7 @@ uint32_t crc32c_3way(uint32_t crc, const char* buf, si
 static inline Function Choose_Extend() {
 #ifdef HAVE_POWER8
   return isAltiVec() ? ExtendPPCImpl : ExtendImpl<Slow_CRC32>;
-#elif defined(__linux__) && defined(HAVE_ARM64_CRC)
+#elif (defined(__FreeBSD__) || defined(__linux__)) && defined(HAVE_ARM64_CRC)
   if(crc32c_runtime_check()) {
     pmull_runtime_flag = crc32c_pmull_runtime_check();
     return ExtendARMImpl;
