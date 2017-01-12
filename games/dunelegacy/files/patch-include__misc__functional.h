--- ./include/misc/functional.h.orig	2011-01-07 18:30:22.000000000 +0000
+++ ./include/misc/functional.h	2014-08-15 18:13:48.592575865 +0000
@@ -1,14 +1,14 @@
 #ifndef FUNCTIONAL_INCLUDED
 #define FUNCTIONAL_INCLUDED
 
-#include <tr1/functional>
+#include <functional>
 
 namespace std {
-	using std::tr1::bind;
-	using std::tr1::function;
+	using std::bind;
+	using std::function;
 
 	namespace placeholders {
-		using namespace std::tr1::placeholders;
+		using namespace std::placeholders;
 	}
 }
 
