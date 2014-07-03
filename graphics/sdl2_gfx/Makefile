# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdl2_gfx
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/%SUBDIR%/
MASTER_SITE_SUBDIR=	SDL2_gfx
DISTNAME=	SDL2_gfx-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

LICENSE=	ZLIB

USES=		pathfix gmake libtool:oldver
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MMX

MMX_CONFIGURE_ENABLE=	mmx
MMX_CFLAGS=		-DUSE_MMX

.include <bsd.port.mk>
