This patch fixed the following build error. It can be removed in later
release since upstream removed compression checks.

Reference:	https://github.com/sunpoet/mongo-c-driver/commit/d35a67a404e3311257b7ad331e4f12d69ce5ec04

--- CMakeFiles/test-libmongoc.dir/tests/test-mongoc-topology.c.o ---
/wrkdirs/usr/ports/devel/mongo-c-driver/work/mongo-c-driver-1.8.1/tests/test-mongoc-topology.c:348:34: error: no member named 'compressors' in 'struct _mongoc_server_description_t'
   BSON_ASSERT (bson_empty (&sd->compressors));
                             ~~  ^
/usr/local/include/libbson-1.0/bson.h:65:26: note: expanded from macro 'bson_empty'
#define bson_empty(b) (((b)->len == 5) || !bson_get_data ((b))[4])
                         ^
/usr/local/include/libbson-1.0/bson-macros.h:192:26: note: expanded from macro 'BSON_ASSERT'
      if (!(BSON_LIKELY (test))) {                         \
                         ^~~~
/usr/local/include/libbson-1.0/bson-macros.h:231:45: note: expanded from macro 'BSON_LIKELY'
#define BSON_LIKELY(x) __builtin_expect (!!(x), 1)
                                            ^
/wrkdirs/usr/ports/devel/mongo-c-driver/work/mongo-c-driver-1.8.1/tests/test-mongoc-topology.c:348:34: error: no member named 'compressors' in 'struct _mongoc_server_description_t'
   BSON_ASSERT (bson_empty (&sd->compressors));
                             ~~  ^
/usr/local/include/libbson-1.0/bson.h:65:60: note: expanded from macro 'bson_empty'
#define bson_empty(b) (((b)->len == 5) || !bson_get_data ((b))[4])
                                                           ^
/usr/local/include/libbson-1.0/bson-macros.h:192:26: note: expanded from macro 'BSON_ASSERT'
      if (!(BSON_LIKELY (test))) {                         \
                         ^~~~
/usr/local/include/libbson-1.0/bson-macros.h:231:45: note: expanded from macro 'BSON_LIKELY'
#define BSON_LIKELY(x) __builtin_expect (!!(x), 1)
                                            ^
2 errors generated.
*** [CMakeFiles/test-libmongoc.dir/tests/test-mongoc-topology.c.o] Error code 1

--- tests/test-mongoc-topology.c.orig	2017-10-11 23:52:36 UTC
+++ tests/test-mongoc-topology.c
@@ -345,7 +345,9 @@ _test_topology_invalidate_server (bool p
    BSON_ASSERT (bson_empty (&sd->hosts));
    BSON_ASSERT (bson_empty (&sd->passives));
    BSON_ASSERT (bson_empty (&sd->arbiters));
+#ifdef MONGOC_ENABLE_COMPRESSION
    BSON_ASSERT (bson_empty (&sd->compressors));
+#endif
 
    mongoc_server_stream_cleanup (server_stream);
 
