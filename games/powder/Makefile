# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	powder
PORTVERSION=	115
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.zincland.com/powder/release/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Graphical dungeon crawling game

USES=		gmake sdl
USE_SDL=	sdl
USE_CXXSTD=	c++98
MAKE_JOBS_UNSAFE=yes

BUILD_WRKSRC=	${WRKSRC}/port/linux

PLIST_FILES=	bin/powder
PORTDOCS=	README.TXT LICENSE.TXT CREDITS.TXT

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|bin/bash|bin/sh|' \
		${WRKSRC}/rooms/buildrooms.bash \
		${WRKSRC}/gfx/rebuild.sh
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|' \
		${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/powder ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
