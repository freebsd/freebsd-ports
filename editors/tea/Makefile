# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	tea
PORTVERSION=	50.0.3
CATEGORIES=	editors

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Simple and powerful Qt-based text editor

LICENSE=	GPLv3

USES=		compiler:c++11-lang gl gmake pkgconfig:build qmake qt:5 xorg

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		SPELL
OPTIONS_GROUP_SPELL=	ASPELL HUNSPELL
OPTIONS_DEFAULT=	ASPELL HUNSPELL

USE_QT=		buildtools_build core declarative gui network widgets printsupport
USE_GL=		gl
USE_LOCALE=	en_US.UTF-8

USE_GITHUB=	yes
GH_ACCOUNT=	psemiletov
GH_PROJECT=	${PORTNAME}-qt

LDFLAGS+=	-lz
PLIST_FILES=	bin/tea share/pixmaps/tea_icon_v2.png
PORTDOCS=	*

DESKTOP_ENTRIES="TEA" "" "${PREFIX}/share/pixmaps/tea_icon_v2.png" \
		"${PORTNAME}" "" ""

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_QMAKE_OFF=	CONFIG+=noaspell

HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_QMAKE_OFF=	CONFIG+=nohunspell

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tea ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/tea_icon_v2.png ${STAGEDIR}${PREFIX}/share/pixmaps
	(cd ${WRKSRC}/manuals \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
