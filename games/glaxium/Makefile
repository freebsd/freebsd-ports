# New ports collection makefile for:	glaxium
# Date created:		21 Jan 2006
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	glaxium
PORTVERSION=	0.5
CATEGORIES=	games
MASTER_SITES=	http://xhosxe.free.fr/glaxium/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL based space-ship "shoot-em-up" game

LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut \
		png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
GNU_CONFIGURE=	yes
USE_GL=		yes
USE_SDL=	sdl mixer
ALL_TARGET=	${PORTNAME}

MAN6=		glaxium.6

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/X11R6|${X11BASE}|g; \
		s|\$datadir/games/glaxium|\$datadir/glaxium|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -i '' -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
