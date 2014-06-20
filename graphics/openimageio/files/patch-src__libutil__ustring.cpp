--- ./src/libutil/ustring.cpp.orig	2014-05-24 01:51:53.000000000 +0930
+++ ./src/libutil/ustring.cpp	2014-06-07 22:05:16.418536133 +0930
@@ -67,8 +67,13 @@
 typedef null_lock<null_mutex> ustring_write_lock_t;
 #endif
 
-
+#if defined(__FreeBSD__) && defined(__i386__) && !defined(__clang__)
+// on a 32bit build using gcc4.2 make_unique() seg faults with the
+// concurrent map enabled when used by openshadinglanguage
+#define USE_CONCURRENT_MAP 0
+#else
 #define USE_CONCURRENT_MAP 1
+#endif
 
 #if USE_CONCURRENT_MAP
 typedef unordered_map_concurrent <string_view, ustring::TableRep *, Strutil::StringHash, Strutil::StringEqual, 8> UstringTable;
