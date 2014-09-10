# $FreeBSD$

PORTNAME=	assistant
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 5 documentation browser

USE_QT5=	core help network printsupport sql webkit widgets \
		buildtools_build sql-sqlite3_run
QT_DIST=	tools
USES=		qmake

DESKTOP_ENTRIES="Qt 5 Assistant" "" \
		"${PREFIX}/share/pixmaps/assistant-qt5.png" \
		"${PREFIX}/${QT_BINDIR_REL}/assistant" \
		"Development;Qt;" true

# Run qmake also in help/ subdirectory to generate qt_lib_help.pri.
WRKSRC_SUBDIR=	src/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-install:
	${INSTALL_DATA} ${INSTALL_WRKSRC}/images/assistant-128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/assistant-qt5.png

.include <bsd.port.mk>
