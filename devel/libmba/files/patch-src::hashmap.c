--- src/hashmap.c.orig	Tue May 25 18:10:09 2004
+++ src/hashmap.c	Mon Feb 21 00:31:21 2005
@@ -26,6 +26,7 @@
 #include <string.h>
 #include <errno.h>
 #include <stdio.h>
+#include <wchar.h>
 #include "mba/msgno.h"
 #include "mba/iterator.h"
 #include "mba/allocator.h"
