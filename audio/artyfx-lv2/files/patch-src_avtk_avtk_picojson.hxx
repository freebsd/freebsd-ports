--- src/avtk/avtk/picojson.hxx.orig	2018-02-25 11:56:24 UTC
+++ src/avtk/avtk/picojson.hxx
@@ -204,7 +204,11 @@ inline value::value(double n) : type_(number_type)
 #ifdef _MSC_VER
 	        ! _finite(n)
 #elif __cplusplus>=201103L || !(defined(isnan) && defined(isinf))
-	        std::isnan(n) || std::isinf(n)
+#ifdef __GNUC__
+		std::isnan(n) || std::isinf(n)
+#else
+	        isnanf(n) || isinf(n)
+#endif
 #else
 	        isnan(n) || isinf(n)
 #endif
