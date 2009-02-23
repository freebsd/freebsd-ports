--- qt.FreeBSD.mk.orig	2005-03-26 11:48:31.000000000 +0300
+++ qt.FreeBSD.mk	2009-02-23 19:49:47.000000000 +0300
@@ -1,13 +1,13 @@
 # $Id: qt.FreeBSD.mk,v 1.0 2004/11/05 10:22:11 denis Exp $
 
-QTDIR= /usr/X11R6
+QTDIR?=/usr/X11R6
 MOC= ${QTDIR}/bin/moc
 LUPDATE= ${QTDIR}/bin/lupdate
 LRELEASE= ${QTDIR}/bin/lrelease
 QTCFLAGS= ${QTDIR}/include/qt -DQT_NO_COMPAT -pthread
 QTLFLAGS= -L${QTDIR}/lib -lqt-mt -pthread
 
-CFLAGS+= -I${QTCFLAGS}
+CXXFLAGS+= -I${QTCFLAGS}
 LDADD+= ${QTLFLAGS}
 
 SRCMOC= ${MOCS:M*.h:R:S/$/.cxx/g}
@@ -21,4 +21,4 @@
 	${MOC} ${.IMPSRC} -o ${.TARGET}
 
 .cxx.mo:
-	${CXX} ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}
+	${CXX} ${CXXFLAGS} -c ${.IMPSRC} -o ${.TARGET}
