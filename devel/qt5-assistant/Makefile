# $FreeBSD$

PORTNAME=	assistant
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 documentation browser

USES=		compiler:c++11-lang qmake qt-dist:5,tools
USE_QT=		core gui help network printsupport sql widgets \
		buildtools_build sql-sqlite3_run

DESKTOP_ENTRIES="Qt 5 Assistant" "" \
		"${PREFIX}/share/pixmaps/assistant-qt5.png" \
		"${PREFIX}/${QT_BINDIR_REL}/assistant" \
		"Development;Qt;" true

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/src/${PORTNAME}/${PORTNAME}

# Link in QtHelp port
_QT5_ADDITIONAL_LINK=	help

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/images/assistant-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/assistant-qt5.png

.include <bsd.port.mk>
