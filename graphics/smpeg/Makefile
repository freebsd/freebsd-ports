# New ports collection makefile for:	smpeg
# Date created:		2 Feb 2000
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smpeg
PORTVERSION=	0.3.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.lokigames.com/development/download/smpeg/

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=  	SDL-1.1.2:${PORTSDIR}/devel/sdl-devel \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG=	${X11BASE}/bin/gtk12-config
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		SDL_CONFIG="${SDL_CONFIG}" \
		GLBASE="${X11BASE}" \
		CPPFLAGS="-I${X11BASE}/include"

#If you want to try the opengl player (which doesn't seem to work)
#comment out the following line.
CONFIGURE_ARGS=	--disable-opengl-player \
		--enable-mmx

MAN1=		gtv.1 plaympeg.1

.include <bsd.port.mk>
