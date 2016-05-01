--- ddd/LabelH.C.orig	2009-02-11 18:25:07.000000000 +0100
+++ ddd/LabelH.C	2016-04-04 21:29:40.083516000 +0200
@@ -30,8 +30,6 @@
  *  cwikla@wolfram.com
 */
 
-#define new a_new		// Motif 1.1 wants this
-#define class a_class
 extern "C" {
 #include <Xm/XmP.h>
 #include <Xm/LabelP.h>
@@ -41,8 +39,6 @@ extern "C" {
 #include <Xm/ManagerP.h>
 #endif
 }
-#undef new
-#undef class
 
 #include "LabelHP.h"
 #include "casts.h"
