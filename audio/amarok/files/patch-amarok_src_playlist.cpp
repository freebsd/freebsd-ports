
$FreeBSD$

--- amarok/src/playlist.cpp.orig
+++ amarok/src/playlist.cpp
@@ -3168,6 +3168,7 @@
     stream << "</playlist>\n";
 
     QTextStream fstream( &file );
+    fstream.setEncoding( QTextStream::UnicodeUTF8 );
     fstream << buffer;
 }
 
