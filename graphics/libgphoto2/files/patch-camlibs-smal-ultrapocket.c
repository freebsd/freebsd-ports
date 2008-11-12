--- camlibs/smal/ultrapocket.c.orig	2008-10-18 19:55:46.000000000 +0200
+++ camlibs/smal/ultrapocket.c	2008-11-12 09:56:52.000000000 +0100
@@ -33,6 +33,7 @@
 
 #define GP_MODULE "Smal Ultrapocket"
 
+#include <locale.h>
 #ifdef ENABLE_NLS
 #  include <libintl.h>
 #  undef _
