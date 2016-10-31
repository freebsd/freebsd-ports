# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.25
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/SDL_gfx-${PORTVERSION:R}/
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

LICENSE=	ZLIB

USES=		autoreconf gmake libtool pathfix
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE_i386=	MMX
OPTIONS_DEFINE_amd64=	MMX

MMX_CONFIGURE_ENABLE=	mmx
MMX_CFLAGS=		-DUSE_MMX

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MMMX}
# Every platform not supporting the MMX knob must disable
# MMX support explicitly
CONFIGURE_ARGS+=	--disable-mmx
.endif

.include <bsd.port.mk>
