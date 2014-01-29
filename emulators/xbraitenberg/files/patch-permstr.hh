--- permstr.hh.orig
+++ permstr.hh
@@ -4,6 +4,10 @@
 #include <cstddef>
 #include <cstdarg>
 
+class PermString;
+
+PermString permprintf(const char *, ...);
+
 class PermString { struct Doodad; public:
   
     typedef Doodad *Capsule;
@@ -91,7 +95,7 @@
 inline int
 hashcode(PermString s)
 {
-    return (int)(s.cc());
+    return (int)(size_t)(s.cc());
 }
 
 #endif
