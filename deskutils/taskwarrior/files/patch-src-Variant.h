--- src/Variant.h	2015-03-16 08:02:55.000000000 +0900
+++ src/Variant.h	2015-04-12 08:39:14.000000000 +0900
@@ -49,7 +49,11 @@ 
   Variant (const double);
   Variant (const std::string&);
   Variant (const char*);
+#if  defined(__FreeBSD__) && defined(__i386__)
+  Variant (const time_t, const enum type new_type);
+#else
   Variant (const time_t, const enum type new_type = type_date);
+#endif
   ~Variant ();
 
   void source (const std::string&);
