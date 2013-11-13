# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdl2_gfx
PORTVERSION=	1.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/%SUBDIR%/
MASTER_SITE_SUBDIR=	SDL2_gfx
DISTNAME=	SDL2_gfx-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

LICENSE=	ZLIB

USES=		pathfix gmake
USE_AUTOTOOLS=	libtool
USE_SDL=	sdl2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	MMX

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMMX}
CONFIGURE_ARGS+=--enable-mmx
CFLAGS+=	-DUSE_MMX
.else
CONFIGURE_ARGS=--disable-mmx
.endif

.include <bsd.port.mk>
