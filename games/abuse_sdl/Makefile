# New ports collection makefile for:	abuse_sdl
# Date created:				11 May 2002
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	abuse_sdl
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.labyrinth.net.au/~trandor/abuse/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SDL port of the Abuse game engine

USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN6=		abuse-sdl.6

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
