# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libQtAssistantClient
PORTVERSION=	4.6.3
PORTREVISION=	1
CATEGORIES?=	devel
MASTER_SITES=	${MASTER_SITE_QT}
MASTER_SITE_SUBDIR=	archive/qt/${PORTVERSION:R}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-assistant-qassistantclient-library-compat-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation browser integration library

USE_QT4=	qmake_build moc_build rcc_build corelib gui network

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

ALL_TARGET=	first
# stage support
DESTDIRNAME=	INSTALL_ROOT

WRKSRC=		${WRKDIR}/${DISTNAME:C/src/version/}
BUILD_WRKSRC=	${WRKSRC}/lib
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e 's|$$$$\[QT_INSTALL_HEADERS]|${PREFIX}/${QT_INCDIR_REL}|g' \
		-e 's|$$$$\[QT_INSTALL_LIBS]|${PREFIX}/${QT_LIBDIR_REL}|g' \
		${BUILD_WRKSRC}/lib.pro

do-configure:
	@cd ${BUILD_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -spec ${QMAKESPEC} CONFIG+="create_prl link_prl" \
		VERSION="${PORTVERSION}" ${QMAKEFLAGS}

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
			-e 's|.*$$(QMAKE).*||g' ${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
		${BUILD_WRKSRC}/lib/pkgconfig/QtAssistantClient.pc

pre-build:
	${MKDIR} ${BUILD_WRKSRC}/QtAssistant
	${CP} ${BUILD_WRKSRC}/qassistantclient_global.h \
		${BUILD_WRKSRC}/QtAssistant

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtAssistant
	${INSTALL_DATA} ${FILESDIR}/QAssistantClient ${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtAssistant
	${INSTALL_DATA} ${FILESDIR}/QtAssistant ${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtAssistant
	${MKDIR} ${STAGEDIR}${PREFIX}/share/qt4/mkspecs/features
	${INSTALL_DATA} ${WRKSRC}/features/assistant.prf ${STAGEDIR}${PREFIX}/share/qt4/mkspecs/features

.include <bsd.port.mk>
