--- main.c.orig	2001-08-14 20:32:13.000000000 +0800
+++ main.c	2011-09-05 15:21:32.000000000 +0800
@@ -31,33 +31,34 @@
 **	May 25, 2000 Ver 1.0
 */
 
-#include<stdio.h>
-#include<time.h>
-#include<string.h>
-#include<errno.h>
-#include<unistd.h>
-#include<sys/types.h>
-#include<sys/syslimits.h>
-#include<signal.h>
-#include<X11/Intrinsic.h>
-#include<X11/StringDefs.h>
-#include<X11/Xaw/Label.h>
-#include<X11/Xaw/List.h>
-#include<X11/Xaw/Form.h>
-#include<X11/Xaw/Viewport.h>
-#include<X11/Shell.h>
-#include<X11/xpm.h>
-
-#include"key.h"
-
-#include"xjump.h"
-#include"xjump_xlib.h"
-#include"record.h"
-
-#include"picture.xpm"
-#include"title.xpm"
-#include"icon.xbm"
-#include"icon_msk.xbm"
+#include <stdio.h>
+#include <stdlib.h>
+#include <time.h>
+#include <string.h>
+#include <errno.h>
+#include <unistd.h>
+#include <sys/types.h>
+#include <limits.h>
+#include <signal.h>
+#include <X11/Intrinsic.h>
+#include <X11/StringDefs.h>
+#include <X11/Xaw/Label.h>
+#include <X11/Xaw/List.h>
+#include <X11/Xaw/Form.h>
+#include <X11/Xaw/Viewport.h>
+#include <X11/Shell.h>
+#include <X11/xpm.h>
+
+#include "key.h"
+
+#include "xjump.h"
+#include "xjump_xlib.h"
+#include "record.h"
+
+#include "picture.xpm"
+#include "title.xpm"
+#include "icon.xbm"
+#include "icon_msk.xbm"
 
 /***********************************************************
 **
