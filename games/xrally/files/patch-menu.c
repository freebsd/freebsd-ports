--- menu.c	2001/01/01 18:49:16	1.22 XRALLY_1_1
+++ menu.c	2001/01/11 15:28:03	1.23 HEAD
@@ -5,7 +5,7 @@
     copyright            : (C) 2000 by Perdig
     email                : perdig@linuxbr.com.br

-    $Id: menu.c,v 1.22 2001/01/01 18:49:16 perdig Exp $
+    $Id: menu.c,v 1.23 2001/01/11 15:28:03 perdig Exp $
  ***************************************************************************/

 /***************************************************************************
@@ -25,7 +25,9 @@
 #include "level.h"
 #include "score.h"
 #include "dirent.h"
+#ifdef USE_SOUND
 #include "sound.h"
+#endif
 #include "limits.h"
 #include <stdio.h>
 #include <string.h>
