--- third_party/protobuf/src/google/protobuf/stubs/strutil.h.orig	2022-05-11 07:01:56 UTC
+++ third_party/protobuf/src/google/protobuf/stubs/strutil.h
@@ -373,13 +373,13 @@ inline uint32 strtou32(const char *nptr, char **endptr
 inline int64 strto64(const char *nptr, char **endptr, int base) {
   GOOGLE_COMPILE_ASSERT(sizeof(int64) == sizeof(long long),
                         sizeof_int64_is_not_sizeof_long_long);
-  return strtoll(nptr, endptr, base);
+  return std::strtoll(nptr, endptr, base);
 }
 
 inline uint64 strtou64(const char *nptr, char **endptr, int base) {
   GOOGLE_COMPILE_ASSERT(sizeof(uint64) == sizeof(unsigned long long),
                         sizeof_uint64_is_not_sizeof_long_long);
-  return strtoull(nptr, endptr, base);
+  return std::strtoull(nptr, endptr, base);
 }
 
 // ----------------------------------------------------------------------
