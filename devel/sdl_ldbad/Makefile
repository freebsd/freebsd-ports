# New ports collection makefile for:	sdl_ldbad
# Date created:				17 April 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl_ldbad
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A SDL Linux Developer's BandAiD

USE_SDL=	sdl
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-fetch:
	@${DO_NADA}

do-install:
	${LN} -shf ${SDL_CONFIG} ${PREFIX}/bin/sdl-config
	${LN} -shf ${LOCALBASE}/include/SDL11 ${PREFIX}/include/SDL
.for lib in SDL-1.1.a SDL-1.1.so SDL-1.1.so.7 SDLmain-1.1.a
	${LN} -shf ${LOCALBASE}/lib/lib${lib} ${PREFIX}/lib/lib${lib:S/-1.1//}
.endfor
	${LN} -shf ${LOCALBASE}/share/aclocal/sdl11.m4 ${PREFIX}/share/aclocal/sdl.m4

.include <bsd.port.mk>
