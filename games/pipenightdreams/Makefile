# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	pipenightdreams
PORTVERSION=	0.10.0
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/pipenightdreams/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A puzzle game similar to PipeMania

USE_SDL=	image sdl
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

MAN6=		pipenightdreams.6

NO_STAGE=	yes
.include <bsd.port.pre.mk>

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
