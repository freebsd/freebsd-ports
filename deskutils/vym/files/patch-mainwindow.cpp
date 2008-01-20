--- mainwindow.cpp.orig	Tue Sep  4 15:53:33 2007
+++ mainwindow.cpp	Tue Jan  1 20:35:11 2008
@@ -140,7 +140,7 @@
 			#if defined(Q_OS_MACX)
 				s=settings.value (p,"/usr/bin/open").toString();
 			#else
-				s=settings.value (p,"mozilla");
+				s=settings.value (p,"mozilla").toString();
 			#endif
 		#endif
 		settings.setValue( p,s);
@@ -3637,6 +3637,7 @@
 	searchList << "doc/tex";	// Easy testing working on vym.tex
 	searchList << "/usr/share/doc/vym";	// Debian
 	searchList << "/usr/share/doc/packages";// Knoppix
+	searchList << "/usr/local/share/doc/vym"; //FreeBSD
 
 	bool found=false;
 	QFile docfile;
