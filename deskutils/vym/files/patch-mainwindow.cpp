--- mainwindow.cpp.orig	2008-05-05 15:46:42.000000000 +0200
+++ mainwindow.cpp	2008-08-03 20:13:53.000000000 +0200
@@ -3715,6 +3715,7 @@
 	searchList << "doc/tex";	// Easy testing working on vym.tex
 	searchList << "/usr/share/doc/vym";	// Debian
 	searchList << "/usr/share/doc/packages";// Knoppix
+	searchList << "/usr/local/share/doc/vym";// FreeBSD
 
 	bool found=false;
 	QFile docfile;
