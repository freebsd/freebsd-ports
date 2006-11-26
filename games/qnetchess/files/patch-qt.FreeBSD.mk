--- qt.FreeBSD.mk.orig	Sat Mar 26 11:48:31 2005
+++ qt.FreeBSD.mk	Sun Nov 26 20:29:14 2006
@@ -1,6 +1,6 @@
 # $Id: qt.FreeBSD.mk,v 1.0 2004/11/05 10:22:11 denis Exp $
 
-QTDIR= /usr/X11R6
+QTDIR?= /usr/X11R6
 MOC= ${QTDIR}/bin/moc
 LUPDATE= ${QTDIR}/bin/lupdate
 LRELEASE= ${QTDIR}/bin/lrelease
