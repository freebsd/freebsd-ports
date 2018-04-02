Provide full definition of IDrawContext, needed when #including
this file in a context (ha!) without that definition already.

--- src/qmapshack/dem/IDem.h.orig	2018-02-23 16:39:15 UTC
+++ src/qmapshack/dem/IDem.h
@@ -19,6 +19,7 @@
 #ifndef IDEM_H
 #define IDEM_H
 
+#include "canvas/IDrawContext.h"
 #include "canvas/IDrawObject.h"
 #include <QObject>
 #include <QPointer>
