# $FreeBSD$

PORTNAME=	qdbusviewer
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 graphical interface to D-Bus

USE_QT=		core dbus gui widgets xml buildtools_build
USES=		compiler:c++11-lang qmake qt-dist:5,tools

DESKTOP_ENTRIES="Qt 5 D-Bus Viewer" "" \
		"${PREFIX}/share/pixmaps/qdbusviewer-qt5.png" \
		"${PREFIX}/${QT_BINDIR_REL}/qdbusviewer" \
		"Development;Qt;" true

BUILD_WRKSRC=	${WRKSRC}/src/qdbus/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/images/qdbusviewer-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/qdbusviewer-qt5.png

.include <bsd.port.mk>
