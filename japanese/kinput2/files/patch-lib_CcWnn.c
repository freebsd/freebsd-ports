Index: lib/CcWnn.c
===================================================================
RCS file: /home/cvs/private/hrs/kinput2/lib/CcWnn.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
--- lib/CcWnn.c.orig	2002-10-03 09:35:27 UTC
+++ lib/CcWnn.c
@@ -18,6 +18,8 @@ static char *rcsid = "$Id: CcWnn.c,v 1.5
  * Author:  Makoto Ishisone, Software Research Associates, Inc., Japan
  */
 
+#include <stdlib.h>
+
 #include <X11/IntrinsicP.h>
 #include <X11/StringDefs.h>
 #include <X11/Xmu/Atoms.h>
@@ -854,6 +856,10 @@ CcWnnObject obj;
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
