PORTNAME=	linguist
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 translation tool

USES=		compiler:c++11-lang qmake qt-dist:5,tools
USE_QT=		core gui printsupport widgets xml \
		assistant_run linguisttools_run \
		buildtools_build designer_build uitools_build

DESKTOP_ENTRIES="Qt 5 Linguist" "" \
		"${PREFIX}/share/pixmaps/linguist-qt5.png" \
		"${PREFIX}/${QT_BINDIR_REL}/linguist" \
		"Development;Qt;" true

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/${PORTNAME}/${PORTNAME}

QT_BINARIES=	yes

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/images/icons/linguist-128-32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/linguist-qt5.png

.include <bsd.port.mk>
