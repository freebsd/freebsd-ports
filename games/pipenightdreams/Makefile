# New ports collection makefile for:	pipenightdreams
# Date created:			Apr 12, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	pipenightdreams
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/pipenightdreams/packages/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	A puzzle game similar to PipeMania

USE_SDL=	image sdl
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
USE_REINPLACE=	yes

MAN6=		pipenightdreams.6

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

post-patch:
	${REINPLACE_CMD} 's|"SDL/SDL|"SDL|g ; s|<SDL/SDL|<SDL|g; \
		s|SDL_LIBSS|SDL_LIBS|g; s|datadir/games|datadir|;' \
		${WRKSRC}/configure
	${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} 's|/games/|/|g; \
			s/^pipenightdreams_LDADD.+//g;'
	${REINPLACE_CMD} "s|/usr/share/games|${LOCALBASE}/share|g" \
		${WRKSRC}/src/main.cpp

.include <bsd.port.post.mk>
