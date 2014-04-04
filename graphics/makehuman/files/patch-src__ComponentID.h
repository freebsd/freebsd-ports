--- src/ComponentID.h.orig	2007-12-03 01:30:18.000000000 +0300
+++ src/ComponentID.h	2013-09-14 14:26:25.451226331 +0400
@@ -27,6 +27,8 @@
 #ifndef COMPONENTID_H
 #define COMPONENTID_H 1
 
+#include <algorithm> // for for_each in *Panel.cpp
+
 #ifdef HAVE_CONFIG_H
   #include <config.h>
 #endif
