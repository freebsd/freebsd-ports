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
LDFLAGS+=	-lm

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/newvox ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/newvox
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/newvox

.include <bsd.port.mk>
