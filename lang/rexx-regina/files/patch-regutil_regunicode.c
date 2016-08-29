--- regutil/regunicode.c.orig	2012-08-08 01:26:20 UTC
+++ regutil/regunicode.c
@@ -20,6 +20,7 @@
  *
  * $Header: /opt/cvs/Regina/regutil/regunicode.c,v 1.3 2012/08/08 01:26:20 mark Exp $
  */
+#include </usr/include/strings.h>
 #include "rxproto.h"
 
 #ifdef _WIN32
