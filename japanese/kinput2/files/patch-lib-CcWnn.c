--- lib/CcWnn.c.orig	2002-10-03 18:35:27.000000000 +0900
+++ lib/CcWnn.c	2008-12-28 13:32:01.000000000 +0900
@@ -18,6 +18,8 @@
  * Author:  Makoto Ishisone, Software Research Associates, Inc., Japan
  */
 
+#include <stdlib.h>
+
 #include <X11/IntrinsicP.h>
 #include <X11/StringDefs.h>
 #include <X11/Xmu/Atoms.h>
@@ -854,6 +856,10 @@
 	 * で、覚えておく。
 	 */
 	current_obj = obj;
+	/* Use JSERVER if defined instead of any other configurations */
+	if (getenv("JSERVER") != NULL) {
+		obj->ccWnn.jservername = getenv("JSERVER");
+	}
 	obj->ccWnn.wnnbuf = jcOpen2(obj->ccWnn.jservername,
 				    obj->ccWnn.wnnenvname,
 				    obj->ccWnn.wnnoverrideenv,
