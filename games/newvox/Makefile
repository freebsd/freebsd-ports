# Ports collection makefile for:  newvox
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	newvox
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newvox ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/newvox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/newvox
.endif

.include <bsd.port.mk>
