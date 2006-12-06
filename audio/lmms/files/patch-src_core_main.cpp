--- src/core/main.cpp.orig	Mon Dec  4 15:22:34 2006
+++ src/core/main.cpp	Wed Dec  6 11:52:51 2006
@@ -49,6 +49,9 @@
 #include <sched.h>
 #endif
 
+#include <sys/types.h>
+#include <unistd.h>
+
 
 #include "main_window.h"
 #include "embed.h"
@@ -89,6 +92,7 @@
 		printf( "could not set realtime priority.\n" );
 	}
 #endif
+	setuid(getuid());	// drop root privileges
 
 	QApplication app( argc, argv );
 
