# ex:ts=8
# Ports collection makefile for:	race
# Date created:			Jul 16, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	race
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://users.freebsd.org.uk/pub/foobar2k/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL Racing Game

USE_SDL=	mixer image sdl
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_MESA=	yes
CFLAGS+=	"-I${X11BASE}/include"
MAKE_ENV=	CC="${CC} ${CFLAGS}" LDFLAGS="-L${X11BASE}/lib ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" \
		-e "s|sdl-config|${SDL_CONFIG}|g" ${WRKSRC}/Makefile
.for file in  game.c main.c menu.c terrain.c textures.c
	@${REINPLACE_CMD} -e "s|%%DATADIR%%|${DATADIR}|g" ${WRKSRC}/src/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/race ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/config ${DATADIR}
	${CP} -R ${WRKSRC}/data/* ${DATADIR}/data

.include <bsd.port.mk>
