PORTNAME=	gzdoom
PORTVERSION=	4.7.1
DISTVERSIONPREFIX=	g
PORTREVISION=	7
CATEGORIES=	games

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	GL-enhanced source port for Doom-engine games
WWW=		https://zdoom.org/

LICENSE=	BSD3CLAUSE GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/docs/licenses/bsd.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/docs/licenses/gpl.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/docs/licenses/lgpl.txt

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libzmusic.so:audio/zmusic

USES=		cmake compiler:c++11-lang gnome jpeg pkgconfig sdl

DATADIR=	${DMDIR}/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	coelckers

CMAKE_ARGS=	-DINSTALL_DOCS_PATH=${DOCSDIR}	\
		-DINSTALL_PK3_PATH=${DMDIR}	\
		-DINSTALL_SOUNDFONT_PATH=${DMDIR} \
		-DDYN_GTK:BOOL=OFF

USE_GNOME=	gtk30
USE_SDL=	sdl2
CXXFLAGS+=	-DSHARE_DIR=\\\"${DATADIR}\\\"
LDFLAGS+=	-Wl,--as-needed

DESKTOP_ENTRIES=	"GZDoom" "" "${PORTNAME}" "${PORTNAME}" "Game;Shooter;" ""

.include "${.CURDIR}/../doom-data/Makefile.include"

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.xpm \
	    ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
