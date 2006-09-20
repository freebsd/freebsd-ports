# ex:ts=8
# Ports collection makefile for:	ggz-sdl-games
# Date created:			Nov 7, 2005
# Whom:				yinjieh
#
# $FreeBSD$
#

PORTNAME=	ggz-sdl-games
PORTVERSION=	0.0.13
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://mirrors.dotsrc.org/ggzgamingzone/ggz/%SUBDIR%/ \
		http://ftp.ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DIST_SUBDIR=	ggz

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - SDL-based games

LIB_DEPENDS=	ggzcore.8:${PORTSDIR}/games/ggz-client-libs

USE_GETOPT_LONG=	yes
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
