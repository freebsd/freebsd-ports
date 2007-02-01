# ex:ts=8
# Ports collection makefile for:	sdl_gfx
# Date created:			Apr 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.13
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/%SUBDIR%/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
MASTER_SITE_SUBDIR=	SDL_gfx-${PORTVERSION:R}
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	shaun@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

USE_AUTOTOOLS=	libtool:15
USE_SDL=	sdl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--includedir=${PREFIX}/include \
		--disable-mmx
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
CFLAGS+=	-DUSE_MMX
.endif

.include <bsd.port.post.mk>
