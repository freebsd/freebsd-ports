--- hero.c.orig	2011-09-05 15:17:02.000000000 +0800
+++ hero.c	2011-09-05 15:17:21.000000000 +0800
@@ -31,12 +31,13 @@
 **	May 25, 2000 Ver 1.0
 */
 
-#include<stdio.h>
-#include<X11/Xlib.h>
-
-#include"xjump.h"
-#include"xjump_xlib.h"
-#include"key.h"
+#include <stdio.h>
+#include <stdlib.h>
+#include <X11/Xlib.h>
+
+#include "xjump.h"
+#include "xjump_xlib.h"
+#include "key.h"
 
 void HERO_delete( hero_t *hp )
 {
