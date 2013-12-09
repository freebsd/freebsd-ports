--- src/spot/spot.cxx.orig	2013-11-18 20:31:18.824757958 -0500
+++ src/spot/spot.cxx	2013-11-18 20:34:28.424968955 -0500
@@ -23,7 +23,11 @@
 #include <config.h>
 
 #include <list>
+#ifdef __clang__
+#include <unordered_map>
+#else
 #include <tr1/unordered_map>
+#endif
 #include <functional>
 
 #include "trx.h"
@@ -60,9 +64,14 @@
 };
 
 typedef list<callback_t*> callback_p_list_t;
+#ifdef __clang__
+typedef std::unordered_map<fre_t*, callback_p_list_t, fre_hash, fre_comp> rcblist_t;
+static std::unordered_map<int, string> buffers;
+#else
 typedef tr1::unordered_map<fre_t*, callback_p_list_t, fre_hash, fre_comp> rcblist_t;
 
 static tr1::unordered_map<int, string> buffers;
+#endif
 static cblist_t cblist;
 static rcblist_t rcblist;
 
