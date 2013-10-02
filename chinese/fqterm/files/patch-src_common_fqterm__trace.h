--- src/common/fqterm_trace.h.orig	2013-10-02 06:06:02.000000000 +0000
+++ src/common/fqterm_trace.h
@@ -21,6 +21,7 @@
 #ifndef FQTERM_TRACE_H
 #define FQTERM_TRACE_H
 
+#include <unistd.h>
 #include <cassert>
 #include <QtDebug>
 #include <QFileInfo>
