--- ./common/memory.c.orig	2006-12-17 12:06:05.000000000 -0500
+++ ./common/memory.c	2010-01-27 13:52:46.000000000 -0500
@@ -1,6 +1,5 @@
 #include <string.h>
 #include <limits.h>
-#include <malloc.h>
 
 #if (!defined(XFRACT) && !defined(WINFRACT))
 #include <io.h>
