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
COMMENT=	Qt 4 Solutions Single Application Framework

USES=		qmake
USE_QT4=	moc_build rcc_build uic_build gui network
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/qt-solutions-qt-solutions/qtsingleapplication
BUILD_WRKSRC=	${WRKSRC}/buildlib
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	${LIBRARY_HEADERS:S,^,include/,} \
		lib/${LIBRARY_NAME} \
		lib/${LIBRARY_NAME}.1

LIBRARY_NAME=	libQtSolutions_SingleApplication-head.so
LIBRARY_HEADERS=	qtsingleapplication.h qtsinglecoreapplication.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${LIBRARY_HEADERS:S,^,${WRKSRC}/src/,} ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/lib/${LIBRARY_NAME}.1.0.0 ${STAGEDIR}${PREFIX}/lib/${LIBRARY_NAME}.1
	${LN} -sf ${LIBRARY_NAME}.1 ${STAGEDIR}${PREFIX}/lib/${LIBRARY_NAME}

.include <bsd.port.mk>
