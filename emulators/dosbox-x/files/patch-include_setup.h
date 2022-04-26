--- include/setup.h.orig	2022-04-01 04:26:03 UTC
+++ include/setup.h
@@ -20,6 +20,8 @@
 #ifndef DOSBOX_SETUP_H
 #define DOSBOX_SETUP_H
 
+#include <stdio.h>
+
 #ifdef _MSC_VER
 //#pragma warning ( disable : 4786 )
 //#pragma warning ( disable : 4290 )
