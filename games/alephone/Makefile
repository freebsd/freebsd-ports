# New ports collection makefile for:	AlephOne
# Date created:		27 February 2001
# Whom:			Michael Alyn Miller <malyn@strangeGizmo.com>
#
# $FreeBSD$
#

PORTNAME=	AlephOne
PORTVERSION=	0.11.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	marathon
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} AlephOne-minf-demo.tar.gz

MAINTAINER=	malyn@strangeGizmo.com

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl-devel:install

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-install:
	${INSTALL_DATA} ${WRKDIR}/Images ${PREFIX}/share/AlephOne/Images
	${INSTALL_DATA} ${WRKDIR}/MML/Preferences.mml ${PREFIX}/share/AlephOne/MML/Preferences.mml
	${INSTALL_DATA} ${WRKDIR}/Map ${PREFIX}/share/AlephOne/Map
	${INSTALL_DATA} ${WRKDIR}/README ${PREFIX}/share/AlephOne/README
	${INSTALL_DATA} ${WRKDIR}/Shapes ${PREFIX}/share/AlephOne/Shapes
	${INSTALL_DATA} ${WRKDIR}/Sounds ${PREFIX}/share/AlephOne/Sounds
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
