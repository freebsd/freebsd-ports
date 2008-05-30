--- src/misc/conf.h.orig	2007-12-15 15:16:37.000000000 +0200
+++ src/misc/conf.h	2008-03-16 16:43:14.000000000 +0200
@@ -38,6 +38,9 @@
 #include <core/coredefs.h>
 
 
+typedef unsigned long ulong;
+
+
 typedef struct {
      bool                                init;
 
