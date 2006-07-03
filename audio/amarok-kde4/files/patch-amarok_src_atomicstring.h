
$FreeBSD$

--- amarok/src/atomicstring.h.orig
+++ amarok/src/atomicstring.h
@@ -34,7 +34,7 @@
 #define AMAROK_ATOMICSTRING_H
 
 #include "config.h"
-#ifdef __GNUC__
+#if __GNUC__ >= 3
     #include <ext/hash_set>
 #else
     #include <set>
@@ -136,12 +136,18 @@
     uint refcount() const;
 
 private:
-    #ifdef __GNUC__
+    #if __GNUC__ >= 3
         struct SuperFastHash;
         struct equal;
         typedef __gnu_cxx::hash_set<QString*, SuperFastHash, equal> set_type;
     #else
-        struct less;
+	struct less
+	{
+	bool operator()( const QString *a, const QString *b ) const
+	{
+	return *a < *b;
+	}
+	};
         typedef std::set<QString*, less> set_type;
     #endif
 
