# ex:ts=8
# Ports collection makefile for:	sdl_gfx
# Date created:			Apr 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.19
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/%SUBDIR%/
MASTER_SITE_SUBDIR=	SDL_gfx-${PORTVERSION:R}
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool:22
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
USE_LDCONFIG=	yes

OPTIONS=	MMX	"Enable MMX instruction set (i386 only)"	Off

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CONFIGURE_ARGS+=--enable-mmx
CFLAGS+=	-DUSE_MMX
.else
CONFIGURE_ARGS=--disable-mmx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\$(libdir)/pkgconfig|\$(libdir)/libdata/pkgconfig|' \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
