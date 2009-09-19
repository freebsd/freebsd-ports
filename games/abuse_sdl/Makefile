# New ports collection makefile for:	abuse_sdl
# Date created:				11 May 2002
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	abuse_sdl
PORTVERSION=	0.7.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://abuse.zoy.org/raw-attachment/wiki/Downloads/
DISTNAME=	abuse-sdl-${PORTVERSION}

MAINTAINER=	chris@officialunix.com
COMMENT=	An SDL port of the Abuse game engine

USE_GL=		gl
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		abuse-sdl.6

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
