# Created by: Yuri Momotiuk <yurkis@gmail.com>
# $FreeBSD$

PORTNAME=	qt4-qtsolutions-singleapplication
PORTVERSION=	20110722
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.pcbsd.org/pub/software/ \
		http://www.pcbsd.org/~kris/software/
DISTNAME=	qt4-qtsolutions-singleinstance-${PORTVERSION}

MAINTAINER=	yurkis@gmail.com
COMMENT=	QT4 Solutions Single Application Framework

USE_QT4?=	qmake_build moc_build rcc_build uic_build gui network
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/qt-solutions-qt-solutions/${SUB_PROJECT_NAME}
BUILD_WRKSRC=	${WRKSRC}/buildlib

PLIST_FILES=	${LIBRARY_HEADERS:S,^,include/,} \
		lib/${LIBRARY_NAME} \
		lib/${LIBRARY_NAME}.1

SUB_PROJECT_NAME=	qtsingleapplication
QMAKE_PRO=	buildlib.pro

LIBRARY_NAME=	libQtSolutions_SingleApplication-head.so
LIBRARY_HEADERS=	qtsingleapplication.h qtsinglecoreapplication.h

NO_STAGE=	yes
do-configure:
	cd ${BUILD_WRKSRC} && ${QMAKE} ${QMAKEFLAGS} ${QMAKE_PRO}

do-install:
	${MKDIR} ${PREFIX}/include ${PREFIX}/lib
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${LIBRARY_HEADERS} ${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/lib/${LIBRARY_NAME}.1.0.0 ${PREFIX}/lib/${LIBRARY_NAME}.1
	${LN} -sf ${PREFIX}/lib/${LIBRARY_NAME}.1 ${PREFIX}/lib/${LIBRARY_NAME}

.include <bsd.port.mk>
