--- src/bzflag/resources.h.orig	Thu Oct 17 04:38:17 2002
+++ src/bzflag/resources.h	Mon Dec  9 22:11:54 2002
@@ -21,6 +21,8 @@
 #include "BzfString.h"
 #include "bzfio.h"
 
+using namespace std;
+
 class ResourceDatabase {
   public:
 			ResourceDatabase();
