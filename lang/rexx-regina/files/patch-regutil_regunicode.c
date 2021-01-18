--- regutil/regunicode.c.orig	2019-10-06 06:19:40 UTC
+++ regutil/regunicode.c
@@ -20,6 +20,7 @@
  *
  * $Header: /opt/cvs/Regina/regutil/regunicode.c,v 1.5 2019/07/03 22:39:28 mark Exp $
  */
+#include </usr/include/strings.h>
 #include "rxproto.h"
 
 #ifdef _WIN32
