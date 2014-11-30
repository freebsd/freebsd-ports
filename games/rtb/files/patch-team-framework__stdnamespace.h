--- team-framework/stdnamespace.h.orig	2005-01-06 20:59:18.000000000 +0300
+++ team-framework/stdnamespace.h	2014-11-30 22:10:41.000000000 +0300
@@ -26,8 +26,4 @@
 **************************************************************************/
 
 #include <iosfwd>	// This file contains the forward declaration in particular of std::string
-
-namespace std
-{
-	template <class _Tp> class auto_ptr;	// Origin: The header file <memory>
-}
+#include <memory>
