--- ./kchart/kdchart/KDChartPainter.cpp.orig	Tue Aug 13 18:11:14 2002
+++ ./kchart/kdchart/KDChartPainter.cpp	Tue Aug 13 18:11:41 2002
@@ -8,6 +8,8 @@
   Copyright (C) 2001 by Klarälvdalens Datakonsult AB
 */
 
+#include <cmath>
+#include <stdlib.h>
 #include <KDDrawText.h>
 #include <KDChartPainter.h>
 #include <KDChartEnums.h>
