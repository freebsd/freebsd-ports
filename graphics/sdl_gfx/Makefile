# ex:ts=8
# Ports collection makefile for:	sdl_gfx
# Date created:			Apr 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/~aschiffler/Software/%SUBDIR%/
MASTER_SITE_SUBDIR=	SDL_gfx-${PORTVERSION:R}
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

USE_SDL=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/SDL11 \
		--disable-mmx
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CFLAGS+=	-DUSE_MMX
.endif

post-patch:
	@${GREP} -lR "<SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|<SDL/SDL|<SDL|g'

.include <bsd.port.post.mk>
