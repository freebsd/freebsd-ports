Fix build with Qt 6.6.x

https://github.com/ra3xdh/qucs_s/issues/375
https://github.com/ra3xdh/qucs_s/pull/376

--- qucs/diagrams/marker.h.orig	2023-10-26 12:53:59 UTC
+++ qucs/diagrams/marker.h
@@ -18,6 +18,8 @@
 #ifndef MARKER_H
 #define MARKER_H
 
+#include <vector>
+
 #include "element.h"
 #include "viewpainter.h"
 
