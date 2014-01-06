# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	libQtAssistantClient
PORTVERSION=	4.6.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_QT}
MASTER_SITE_SUBDIR=	archive/qt/${PORTVERSION:R}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-assistant-qassistantclient-library-compat-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation browser integration module

USE_QT4=	moc_build rcc_build corelib gui network
USES=		qmake
QMAKE_ARGS=	CONFIG+="create_prl link_prl" VERSION="${PORTVERSION}"

USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

ALL_TARGET=	first

DESCR=		${.CURDIR:H:H}/devel/qt4/pkg-descr

WRKSRC=		${WRKDIR}/${DISTNAME:C/src/version/}/lib

pre-configure:
	${REINPLACE_CMD} -e 's|$$$$\[QT_INSTALL_HEADERS]|${PREFIX}/${QT_INCDIR_REL}|g' \
		-e 's|$$$$\[QT_INSTALL_LIBS]|${PREFIX}/${QT_LIBDIR_REL}|g' \
		${WRKSRC}/lib.pro

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/${QT_LIBDIR_REL}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
			-e 's|.*$$(QMAKE).*||g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/${QT_BINDIR_REL}/${MOC:T}|g' \
		${WRKSRC}/lib/pkgconfig/QtAssistantClient.pc

pre-build:
	${MKDIR} ${WRKSRC}/QtAssistant
	${CP} ${WRKSRC}/qassistantclient_global.h \
		${WRKSRC}/QtAssistant

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtAssistant
	${INSTALL_DATA} ${FILESDIR}/QAssistantClient ${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtAssistant
	${INSTALL_DATA} ${FILESDIR}/QtAssistant ${STAGEDIR}${PREFIX}/${QT_INCDIR_REL}/QtAssistant
	${MKDIR} ${STAGEDIR}${PREFIX}/${QT_MKSPECDIR_REL}/features
	${INSTALL_DATA} ${WRKSRC:H}/features/assistant.prf ${STAGEDIR}${PREFIX}/${QT_MKSPECDIR_REL}/features

.include <bsd.port.mk>
