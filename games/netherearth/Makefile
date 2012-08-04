# New ports collection makefile for:	netherearth
# Date created:				18 May 2008
# Whom:					Ginzburg Oleg
#
# $FreeBSD$
#

PORTNAME=	netherearth
PORTVERSION=	0.51
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://move.kirishi.ru/soft/netherearth/

MAINTAINER=	olevole@olevole.ru
COMMENT=	Remake of the very first real time strategy game on the SPECTRUM

GNU_CONFIGURE=	yes

USE_GL=		glut
USE_SDL=	sdl mixer

pre-install:
	if [ ! -d ${PREFIX}/share/netherearth ] ; then \
		${MKDIR} ${PREFIX}/share/netherearth ;\
	fi
	${CP} -R ${WRKSRC}/maps ${PREFIX}/share/netherearth/
	${CP} -R ${WRKSRC}/models ${PREFIX}/share/netherearth/
	${CP} -R ${WRKSRC}/sound ${PREFIX}/share/netherearth/
	${CP} -R ${WRKSRC}/textures ${PREFIX}/share/netherearth/

.include <bsd.port.mk>
