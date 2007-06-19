# New ports collection makefile for:	glaxium
# Date created:		21 Jan 2006
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	glaxium
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://xhosxe.free.fr/glaxium/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL based space-ship "shoot-em-up" game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnometarget
USE_SDL=	sdl mixer
USE_GL=		glut
USE_GMAKE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

MAN6=		glaxium.6

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g; \
		 s|/games/glaxium|/glaxium|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gcc -g -o|$$(CC) -o|g ; \
		 s|/games/glaxium|/glaxium|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|Scratcher:: Scratcher|Scratcher|g' \
		${WRKSRC}/scratcher.hpp
	@${REINPLACE_CMD} -e 's|TankFire::TankFire|TankFire|g' \
		${WRKSRC}/tank.hpp

.include <bsd.port.mk>
