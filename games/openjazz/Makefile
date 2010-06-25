# New ports collection makefile for: openjazz
# Date created:					01 Apr 2008
# Whom:							Ganael Laplanche <ganael.laplanche@martymac.com>
#
# $FreeBSD$
#

PORTNAME=	openjazz
PORTVERSION=	20100427
CATEGORIES=	games
MASTER_SITES=	http://alister.eu/jazz/oj/
DISTNAME=	OpenJazz-src-270410

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Free re-implementation of the Jazz Jackrabbit(tm) game engine

WRKSRC=	${WRKDIR}

USE_ZIP=	yes
USE_GMAKE=	yes
ALL_TARGET=	OpenJazz
USE_XORG=	x11 xext xrandr xrender xau xdmcp
USE_SDL=	sdl

CPPFLAGS=	"-I${LOCALBASE}/include `${SDL_CONFIG} --cflags` \
		-DDATAPATH=\\\"${DATADIR}/\\\" -DHOMEDIR"
LDFLAGS=	"-L${LOCALBASE}/lib ${PTHREAD_LIBS} `${SDL_CONFIG} --libs`"
MAKE_ENV=	CPPFLAGS=${CPPFLAGS} LDFLAGS=${LDFLAGS}

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/openjazz.000 ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKDIR}/OpenJazz ${PREFIX}/bin/openjazz
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
