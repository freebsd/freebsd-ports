--- qterm/qtermiplocation.cpp.orig	Tue Dec  7 03:23:24 2004
+++ qterm/qtermiplocation.cpp	Fri Dec 17 19:24:22 2004
@@ -9,8 +9,8 @@
 #ifdef Q_OS_WIN32
 #include <winsock2.h>
 #else
-#include <netinet/in.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #endif
 
 #include <qstring.h>
@@ -79,13 +79,13 @@
 	if( fseek( fp, (long)offset, SEEK_SET ) ==-1 )
 	{
 		qDebug( " readLineFrom error 1 " );
-		ret_str = QCString(NULL);
+		ret_str = QCString();
 		return -1;
 	}
 	if( fgets( (char *) str, 512, fp ) == NULL )
 	{
 		qDebug( " readLineFrom error 2 " );
-		ret_str = QCString(NULL);
+		ret_str = QCString();
 		return -1;
 	}
 	ret_str = str;
