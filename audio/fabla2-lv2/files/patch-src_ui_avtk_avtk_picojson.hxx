--- src/ui/avtk/avtk/picojson.hxx.orig	2018-05-29 06:34:11 UTC
+++ src/ui/avtk/avtk/picojson.hxx
@@ -204,7 +204,7 @@ inline value::value(double n) : type_(nu
 #ifdef _MSC_VER
 	        ! _finite(n)
 #elif __cplusplus>=201103L || !(defined(isnan) && defined(isinf))
-	        std::isnan(n) || std::isinf(n)
+	        isnanf(n) || isinf(n)
 #else
 	        isnan(n) || isinf(n)
 #endif
