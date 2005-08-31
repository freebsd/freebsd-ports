--- qt.FreeBSD.mk.orig	Wed Aug 31 03:43:55 2005
+++ qt.FreeBSD.mk	Wed Aug 31 03:45:04 2005
@@ -1,13 +1,13 @@
 # $Id: qt.FreeBSD.mk,v 1.0 2004/11/05 10:22:11 denis Exp $
 
-QTDIR= /usr/X11R6
+QTDIR= ${X11BASE}
 MOC= ${QTDIR}/bin/moc
 LUPDATE= ${QTDIR}/bin/lupdate
 LRELEASE= ${QTDIR}/bin/lrelease
-QTCFLAGS= ${QTDIR}/include -DQT_NO_COMPAT -pthread
-QTLFLAGS= -L${QTDIR}/lib -lqt-mt -pthread
+QTCFLAGS= -I${QTDIR}/include -DQT_NO_COMPAT ${PTHREAD_CFLAGS}
+QTLFLAGS= -L${QTDIR}/lib -lqt-mt ${PTHREAD_LIBS}
 
-CFLAGS+= -I${QTCFLAGS}
+CXXFLAGS+= ${QTCFLAGS}
 LDADD+= ${QTLFLAGS}
 
 SRCMOC= ${MOCS:M*.h:R:S/$/.cxx/g}
@@ -21,4 +21,4 @@
 	${MOC} ${.IMPSRC} -o ${.TARGET}
 
 .cxx.mo:
-	${CXX} ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}
+	${CXX} ${CXXFLAGS} -c ${.IMPSRC} -o ${.TARGET}
