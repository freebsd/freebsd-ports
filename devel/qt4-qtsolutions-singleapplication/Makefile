# New ports collection makefile for:    qt4-qtsolutions-singleapplication
# Date created:         19 July 2011
# Whom:                 Yuri Momotiuk <yurkis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qt4-qtsolutions-singleapplication
PORTVERSION=	20110722
CATEGORIES=	devel
MASTER_SITES=	http://qt.gitorious.org/qt-solutions/qt-solutions/archive-tarball/
DISTNAME=	4d0c295c
EXTRACT_SUFX=

MAINTAINER=	yurkis@gmail.com
COMMENT=	QT4 Solutions Single Application Framework

USE_QT_VER=	4
QT_COMPONENTS=  qmake_build moc_build rcc_build uic_build gui network

SUB_PROJECT_NAME=qtsingleapplication

WRKSRC=${WRKDIR}/qt-solutions-qt-solutions/${SUB_PROJECT_NAME}
BUILD_WRKSRC=${WRKSRC}/buildlib

QMAKE_PRO=buildlib.pro

USE_LDCONFIG = ${PREFIX}/lib

LIBRARY_SUFFIX=SingleApplication
LIBRARY_HEADERS=${WRKSRC}/src/qtsingleapplication.h ${WRKSRC}/src/qtsinglecoreapplication.h

HAS_CONFIGURE=  yes

do-configure:
	cd ${BUILD_WRKSRC} && ${QMAKE} ${QMAKE_PRO}

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libQtSolutions_${LIBRARY_SUFFIX}-head.so.1.0.0 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libQtSolutions_${LIBRARY_SUFFIX}-head.so.1.0.0 ${PREFIX}/lib/libQtSolutions_${LIBRARY_SUFFIX}-head.so.1.0
	${LN} -sf ${PREFIX}/lib/libQtSolutions_${LIBRARY_SUFFIX}-head.so.1.0.0 ${PREFIX}/lib/libQtSolutions_${LIBRARY_SUFFIX}-head.so.1
	${LN} -sf ${PREFIX}/lib/libQtSolutions_${LIBRARY_SUFFIX}-head.so.1.0.0 ${PREFIX}/lib/libQtSolutions_${LIBRARY_SUFFIX}-head.so
	${INSTALL_DATA} ${LIBRARY_HEADERS} ${PREFIX}/include

.include <bsd.port.mk>
