--- include/BzfString.h.orig	Thu Oct 17 04:29:38 2002
+++ include/BzfString.h	Mon Dec  9 22:08:01 2002
@@ -40,6 +40,8 @@
 #include "common.h"
 #include "bzfio.h"
 
+using std::ostream;
+
 class BzfString {
   public:
 			BzfString();
