--- src/Obj/XDefs.h.orig	2017-04-14 14:21:02 UTC
+++ src/Obj/XDefs.h
@@ -177,40 +177,21 @@
 //		#define __powerpc__
 //	#endif
 
-	#if APL || LIN || MINGW_BUILD
-// TODO: replace this hack with standard conform <unordered_map>, <hash_map> will disappear in the near future
-	#define GCC_VERSION (__GNUC__ * 10000 \
-                               + __GNUC_MINOR__ * 100 \
-                               + __GNUC_PATCHLEVEL__)
-	#if GCC_VERSION >= 40300
-		#include <backward/hash_fun.h>
-		#include <backward/hash_map>
-	#else
		#include <ext/hash_map>
-		#include <ext/hash_fun.h>
-	#endif
-
 		namespace __gnu_cxx {
 			template<>
 			struct hash<std::string>
 			{
 				size_t
 				operator()(const std::string& __s) const
-				{ return __stl_hash_string(__s.c_str()); }
-			};
-
-			template<>
-			struct hash<float>
-			{
-				size_t
-				operator()(const float& __s) const
-				{ return (size_t) __s; }
+				{
+					std::hash<std::string> hash_fn;
+					return hash_fn(__s);
+				}
 			};
 
 		}
-	#else
-		#include <hash_map>
-	#endif
+
 	using namespace	std;				// DEC THIS TO GET THE NEW IOS FUNCTIONS IN fstream, iomanip, and string, which are all new, unlike the old fstream.h, iomanip.h, and string.h
 	using namespace __gnu_cxx;			// DEC THIS TO GET THE NEW IOS FUNCTIONS IN fstream, iomanip, and string, which are all new, unlike the old fstream.h, iomanip.h, and string.h
 	using __gnu_cxx::hash_map;
