# $FreeBSD$

PORTNAME=	linguist
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 translation tool

USE_QT5=	assistant_run core linguisttools_run printsupport \
		uitools_build widgets xml buildtools_build
QT_DIST=	tools
USES=		qmake

DESKTOP_ENTRIES="Qt 5 Linguist" "" \
		"${PREFIX}/share/pixmaps/linguist-qt5.png" \
		"${PREFIX}/${QT_BINDIR_REL}/linguist" \
		"Development;Qt;" true

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/${PORTNAME}/${PORTNAME}

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/images/icons/linguist-128-32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/linguist-qt5.png

.include <bsd.port.mk>
