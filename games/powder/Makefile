# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	powder
PORTVERSION=	115
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.zincland.com/powder/release/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical dungeon crawling game

USE_GMAKE=	yes
USE_SDL=	sdl
MAKE_JOBS_UNSAFE=yes

BUILD_WRKSRC=	${WRKSRC}/port/linux

PLIST_FILES=	bin/powder

PORTDOCS=	README.TXT LICENSE.TXT CREDITS.TXT

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|bin/bash|bin/sh|' \
		${WRKSRC}/rooms/buildrooms.bash \
		${WRKSRC}/gfx/rebuild.sh
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' \
		${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/powder ${PREFIX}/bin/
if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
