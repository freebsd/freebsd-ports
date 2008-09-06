# New ports collection makefile for:	sdl-ball
# Date created:		22 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl-ball
PORTVERSION=	0.10
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arkanoid/Breakout clone with pretty graphics

USE_BZIP2=	yes
USE_SDL=	sdl image ttf
USE_GL=		gl glu

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' \
		${WRKSRC}/main.cpp ${WRKSRC}/menu.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdl-ball ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR}

.include <bsd.port.mk>
