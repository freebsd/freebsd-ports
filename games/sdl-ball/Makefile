# New ports collection makefile for:	sdl-ball
# Date created:		22 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sdl-ball
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arkanoid/Breakout clone with pretty graphics

USE_BZIP2=	yes
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
MAKE_ENV=	DATADIR=${DATADIR}/

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdl-ball ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/themes && ${COPYTREE_SHARE} . ${DATADIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
