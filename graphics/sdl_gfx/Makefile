# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.25
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/%SUBDIR%/
MASTER_SITE_SUBDIR=	SDL_gfx-${PORTVERSION:R}
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

LICENSE=	ZLIB

USES=		gmake libtool pathfix
PATHFIX_MAKEFILEIN=	Makefile.am
USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	-a -c -f
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include
USE_LDCONFIG=	yes

OPTIONS_DEFINE_i386=	MMX

MMX_CONFIGURE_ENABLE=	mmx
MMX_CFLAGS=		-DUSE_MMX

.include <bsd.port.mk>
