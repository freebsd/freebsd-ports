# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	sidplayer
PORTVERSION=	4.4
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://sidplayer.cebix.net/downloads/ \
		CRITICAL
DISTNAME=	SIDPlayer-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	C64 SID tune player

LICENSE=	GPLv2

USE_SDL=	yes
GNU_CONFIGURE=	yes

SDLINCLUDEDIR=	SDL

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/SDL_endian\.h|${SDLINCLUDEDIR}/SDL_endian\.h|' \
		${WRKSRC}/src/main_sdl.cpp

do-install:
	${INSTALL} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/PSID\ Demo/* ${STAGEDIR}${DOCSDIR}

post-install:
	@${ECHO_MSG} "=============================================================="
	@${ECHO_MSG} "A huge SID tune archive can be found at http://hvsc.c64.org/"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "You can find a few examples in ${DOCSDIR}"
.endif
	@${ECHO_MSG} "=============================================================="

.include <bsd.port.mk>
