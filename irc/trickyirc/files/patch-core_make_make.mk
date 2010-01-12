--- core/make/make.mk.orig	2010-01-10 19:00:06.000000000 +0000
+++ core/make/make.mk	2010-01-10 19:00:28.000000000 +0000
@@ -63,7 +63,7 @@
 
 doinst :
 	cp ${BINNAME} ${INSTALLDIR}
-	chown root.bin ${INSTALLDIR}${BINNAME}
+	chown root:bin ${INSTALLDIR}${BINNAME}
 	chmod a+rx ${INSTALLDIR}${BINNAME}
 
 # Messages
