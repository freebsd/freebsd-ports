# ex:ts=8
# New ports collection makefile for:	gnuboy
# Date created:			Mar 11, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnuboy
PORTVERSION=	0.9.12
CATEGORIES=	emulators games
MASTER_SITES=	http://brightrain.aerifal.cx/~laguna/src/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12

USE_XLIB=	yes

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV=	SDL_CONFIG=${SDL_CONFIG} \
		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-sdl

post-patch:
.for file in sys/sdl/sdl.c sys/sdl/keymap.c
	@${PERL} -pi -e "s|SDL/|SDL11/|g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
