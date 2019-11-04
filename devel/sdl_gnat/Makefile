# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sdl_gnat
PORTVERSION=	2013
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ada thin bindings for SDL (GPLv3)

LICENSE=	GPLv3

USES=		ada gl sdl tar:bzip2
USE_SDL=	sdl ttf
USE_GL=		glu gl

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${LOCALBASE}|' \
		${WRKSRC}/gnat_sdl.gpr

.include <bsd.port.mk>
