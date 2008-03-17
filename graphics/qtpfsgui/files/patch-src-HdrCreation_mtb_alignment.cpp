--- src/HdrCreation/mtb_alignment.cpp.orig	2008-03-17 15:55:26.000000000 +0100
+++ src/HdrCreation/mtb_alignment.cpp	2008-03-17 15:57:21.000000000 +0100
@@ -27,6 +27,7 @@
 #include <cassert>
 #include <QVector>
 #include "mtb_alignment.h"
+#include "../arch/freebsd/math.h"
 
 QImage* shiftQImage(const QImage *in, int dx, int dy)
 {
