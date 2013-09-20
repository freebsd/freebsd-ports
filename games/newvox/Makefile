# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	newvox
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Voxel-style landscape rendering fly-by

USE_SDL=	sdl
GNU_CONFIGURE=	yes

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newvox ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/newvox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/newvox
.endif

.include <bsd.port.mk>
