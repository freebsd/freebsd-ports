--- src/src.pro.orig	2007-08-15 01:00:28.000000000 +0400
+++ src/src.pro	2008-02-06 17:30:57.000000000 +0300
@@ -92,7 +92,7 @@
 	incfiles.files += $$QCA_INC/qca.h $$QCA_INC/QtCrypto
 	INSTALLS += incfiles
 
-	manfiles.path = $$DATADIR/man/man1
+	manfiles.path = $$PREFIX/man/man1
 	manfiles.files = $$QCA_BASE/man/qcatool2.1
 	INSTALLS += manfiles
 }
