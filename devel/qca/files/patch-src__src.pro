--- ./src/src.pro.orig	2008-06-04 04:50:25.000000000 +0400
+++ ./src/src.pro	2009-03-15 18:39:38.000000000 +0300
@@ -110,7 +110,7 @@
 	incfiles.files += $$QCA_INC/qca.h $$QCA_INC/QtCrypto
 	!lib_bundle:INSTALLS += incfiles
 
-	manfiles.path = $$DATADIR/man/man1
+	manfiles.path = $$PREFIX/man/man1
 	manfiles.files = $$QCA_BASE/man/qcatool2.1
 	INSTALLS += manfiles
 }
