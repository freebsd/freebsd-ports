--- src/core/main.cpp.orig	2009-02-24 07:34:26.000000000 +0900
+++ src/core/main.cpp	2009-04-09 03:42:57.000000000 +0900
@@ -38,6 +38,9 @@
 #include <QtGui/QPainter>
 #include <QtGui/QSplashScreen>
 
+#include <sys/types.h>
+#include <unistd.h>
+
 #ifdef LMMS_HAVE_SCHED_H
 #include <sched.h>
 #endif
@@ -101,6 +104,8 @@
 		}
 	}
 
+	setuid(getuid());	// drop root privileges
+
 	QCoreApplication * app = core_only ?
 			new QCoreApplication( argc, argv ) :
 					new QApplication( argc, argv ) ;
