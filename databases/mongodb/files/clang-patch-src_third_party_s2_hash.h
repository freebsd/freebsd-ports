--- src/third_party/s2/hash_orig.h	2013-09-15 13:43:35.601932885 +0000
+++ src/third_party/s2/hash.h		2013-09-15 13:43:49.767929768 +0000
@@ -8,8 +8,8 @@
 #define hash_set mongo::unordered_set
 
 #if defined OS_LINUX || defined OS_MACOSX || defined __sunos__ || defined __freebsd__
-#define HASH_NAMESPACE_START namespace std { namespace tr1 {
-#define HASH_NAMESPACE_END }}
+#define HASH_NAMESPACE_START namespace std {
+#define HASH_NAMESPACE_END }
 #elif defined OS_WINDOWS
 #define HASH_NAMESPACE_START namespace std {
 #define HASH_NAMESPACE_END }
