# $FreeBSD$

PORTNAME=	netwalk
PORTVERSION=	0.4.10
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	GITHUB \
		GOOGLE_CODE:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		screenshot-0.4.8.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Game where the object is to connect every terminal to the main server

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	blynn
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	634e7c9

USE_SDL=	sdl ttf
USE_GMAKE=	yes
USES=		iconv
USE_XORG=	x11 xau xdmcp
ALL_TARGET=

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/netwalk/Vera.ttf \
		share/pixmaps/${PORTNAME}.png
PLIST_DIRSTRY=	share/netwalk

PORTDOCS=	README

DESKTOP_ENTRIES="NetWalk" "${COMMENT}" "${PORTNAME}" \
		"${PORTNAME}" "Game;LogicGame;" "false"

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
	-e 's|sdl-config|$(SDL_CONFIG)|' \
	-e 's|CC=gcc|CC?=g++|' \
	-e 's|CFLAGS=-Wall -O2 -fomit-frame-pointer|CFLAGS+=-Wall -O2 -fomit-frame-pointer|' \
	-e 's|PREFIX = /usr|PREFIX = ${PREFIX}|' \
		${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${_DISTDIR}/screenshot-0.4.8.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
