--- qterm/qtermiplocation.cpp.orig	Tue Dec 14 18:45:37 2004
+++ qterm/qtermiplocation.cpp	Tue Dec 14 18:46:21 2004
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
