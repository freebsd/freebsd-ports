--- include/setup.h.orig	2011-10-18 12:06:07.227092555 -0400
+++ include/setup.h	2011-10-18 12:06:26.200853712 -0400
@@ -21,6 +21,8 @@
 #ifndef DOSBOX_SETUP_H
 #define DOSBOX_SETUP_H
 
+#include <stdio.h>
+
 #ifdef _MSC_VER
 #pragma warning ( disable : 4786 )
 #pragma warning ( disable : 4290 )
