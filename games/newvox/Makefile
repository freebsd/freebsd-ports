# Ports collection makefile for:  newvox
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	newvox
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Voxel-style landscape rendering fly-by

USE_SDL=	sdl
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newvox ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/newvox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/newvox
.endif

.include <bsd.port.mk>
