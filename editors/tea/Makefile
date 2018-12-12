# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	tea
PORTVERSION=	46.3.0
PORTREVISION=	2
CATEGORIES=	editors

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Simple and powerful Qt-based text editor

LICENSE=	GPLv3

USES=		compiler:c++11-lang gl pkgconfig:build qmake

OPTIONS_SINGLE=	TOOLKITS
OPTIONS_SINGLE_TOOLKITS=	QT4 QT5
OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		SPELL
OPTIONS_GROUP_SPELL=	ASPELL HUNSPELL
OPTIONS_DEFAULT=	QT5 ASPELL HUNSPELL

USE_GL=		gl
USE_LOCALE=	en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	psemiletov
GH_PROJECT=	${PORTNAME}-qt

QT4_USES=	qt:4
QT4_USE=	qt=corelib,gui,moc_build,network,rcc_build
QT5_USES=	qt:5
QT5_USE=	qt=buildtools_build,core,declarative,gui,network,widgets,printsupport

LDFLAGS+=	-lz
PLIST_FILES=	bin/tea share/pixmaps/tea_icon_v2.png
PORTDOCS=	*

DESKTOP_ENTRIES="TEA" "" "${PREFIX}/share/pixmaps/tea_icon_v2.png" \
		"${PORTNAME}" "" ""

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_QMAKE_OFF=	CONFIG+=noaspell

HUNSPELL_LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell
HUNSPELL_QMAKE_OFF=	CONFIG+=nohunspell

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQT4}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tea ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/tea_icon_v2.png ${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/manuals \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
