# New ports collection makefile for:	foobillard
# Date created:				26 October 2002
# Whom:					Thomas Vogt <thomas.vogt@bsdunix.ch>
#
# $FreeBSD$
#

PORTNAME=	foobillard
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://foobillard.sunsite.dk/dnl/

MAINTAINER=	thomas.vogt@bsdunix.ch
COMMENT=	A free OpenGL-billard game

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
USE_GETOPT_LONG=yes
USE_MESA=	yes
USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
GNU_CONFIGURE=	yes

CPPFLAGS=	-I${X11BASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LIBS="-L${LOCALBASE}/lib"

.if !defined(WITH_NVIDIA_BUMPREF)
CONFIGURE_ARGS+=	--disable-bumpref
.endif

MAN6=		foobillard.6
MANCOMPRESSED=	no

post-install:
	@${INSTALL_MAN} ${WRKSRC}/foobillard.6 ${PREFIX}/man/man6/foobillard.6

.include <bsd.port.mk>
