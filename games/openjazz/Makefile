# New ports collection makefile for: openjazz
# Date created:					01 Apr 2008
# Whom:							Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	openjazz
PORTVERSION=	20070212
CATEGORIES=	games
MASTER_SITES=	http://contribs.martymac.com/FreeBSD-ports/distfiles/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Free re-implementation of the Jazz Jackrabbit(tm) game engine

USE_XORG=	x11 xext xrandr xrender xau xdmcp
USE_SDL=	sdl
MAKE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `${SDL_CONFIG} --cflags`" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} `${SDL_CONFIG} --libs`" \
		INSTALL="${INSTALL}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"

SUB_FILES=	openjazz pkg-message

post-extract:
	@${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/openjazz.000 ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKDIR}/openjazz ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
