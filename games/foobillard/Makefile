# New ports collection makefile for:	foobillard
# Date created:				26 October 2002
# Whom:					Thomas Vogt <thomas.vogt@bsdunix.ch>
#
# $FreeBSD$
#

PORTNAME=	foobillard
PORTVERSION=	1.8
CATEGORIES=	games
MASTER_SITES=	http://foobillard.sunsite.dk/dnl/

MAINTAINER=	thomas.vogt@bsdunix.ch

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
USE_MESA=	yes
USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
USE_REINPLACE=	yes

HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-SDL --prefix=${PREFIX} \
		--includedir="${X11BASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
