--- libshade/yacc.y.orig	1992-02-10 03:04:21 UTC
+++ libshade/yacc.y
@@ -13,6 +13,8 @@
 /* for any purpose.  It is provided solely "as is".			   */
 /* $Id: yacc.y,v 4.0.1.4 92/01/10 16:29:55 cek Exp Locker: cek $ */
 %{
+#include <stdlib.h>
+#include <string.h>
 #include "rayshade.h"
 
 #include "symtab.h"
