# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.24
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/%SUBDIR%/
MASTER_SITE_SUBDIR=	SDL_gfx-${PORTVERSION:R}
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

USES=		pathfix
USE_AUTOTOOLS=	libtool
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
USE_LDCONFIG=	yes

OPTIONS_DEFINE_i386=	MMX

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMMX}
CONFIGURE_ARGS+=--enable-mmx
CFLAGS+=	-DUSE_MMX
.else
CONFIGURE_ARGS=--disable-mmx
.endif

.include <bsd.port.mk>
