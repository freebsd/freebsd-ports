--- chewing.c.orig	Sat Jan 31 14:41:35 2004
+++ chewing.c	Wed Sep  8 04:33:13 2004
@@ -40,7 +40,6 @@
 
 #include "chewingio.h"
 #include "hash.h"
-#include "console_chewing.h"
 #include "dict.h"
 #include "zuin.h"
 
@@ -647,7 +646,7 @@
 	case IM_VK_PAGE_DOWN:
 	    break;
 
-	case KEY_TAB:
+	case '\t':
 	    OnKeyTab(pgdata, op);
 	    break;
 
