# New ports collection makefile for:	smpeg
# Date created:		2 Feb 2000
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smpeg
PORTVERSION=	0.3.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.lokigames.com/development/download/smpeg/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=  	SDL.2:${PORTSDIR}/devel/sdl \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG=	${X11BASE}/bin/gtk12-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLBASE="${X11BASE}" \
		CPPFLAGS="-I${X11BASE}/include"

#If you want to try the opengl player (which doesn't seem to work)
#comment out the following line.
CONFIGURE_ARGS=	--disable-opengl-player

MAN1=		gtv.1 plaympeg.1

.include <bsd.port.mk>
