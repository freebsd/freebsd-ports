--- tools/piqsl/image.h.orig	2012-08-24 12:26:50 UTC
+++ tools/piqsl/image.h
@@ -46,10 +46,12 @@
 #include <QtCore/QObject>
 #include <QtGui/QImage>
 
+#ifndef Q_MOC_RUN
 #include <boost/shared_ptr.hpp>
 #include <boost/shared_array.hpp>
 #include <boost/filesystem/path.hpp>
 #include <boost/thread/mutex.hpp>
+#endif
 
 #include "tinyxml.h"
 
