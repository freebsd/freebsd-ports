# New ports collection makefile for:   sidplayer
# Date created:		27 May 2005
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	sidplayer
PORTVERSION=	4.4
CATEGORIES=	audio
MASTER_SITES=	http://wwwthep.physik.uni-mainz.de/~cbauer/
DISTNAME=	SIDPlayer-${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A C64 SID tune player

USE_SDL=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

SDLINCLUDEDIR=	SDL11

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/SDL_endian\.h|${SDLINCLUDEDIR}/SDL_endian\.h|' \
		${WRKSRC}/src/main_sdl.cpp

do-install:
	${INSTALL} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/PSID\ Demo/* ${DOCSDIR}/
.endif

post-install:
	@${ECHO_MSG} "=============================================================="
	@${ECHO_MSG} "A huge SID tune archive can be found at http://hvsc.c64.org/"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "You can find a few examples in ${DOCSDIR}"
.endif
	@${ECHO_MSG} "=============================================================="

.include <bsd.port.mk>
