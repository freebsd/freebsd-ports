# ex:ts=8
# New ports collection makefile for:	gnuboy
# Date created:			Mar 11, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnuboy
PORTVERSION=	1.0.3
CATEGORIES=	emulators games
MASTER_SITES=	http://gnuboy.unix-fu.org/src/ \
		http://brightrain.aerifal.cx/~laguna/src/

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib \
		SDL-1.1.5:${PORTSDIR}/devel/sdl12

USE_REINPLACE=	yes
USE_XLIB=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV=	SDL_CONFIG=${SDL_CONFIG} \
		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-sdl

post-patch:
.for file in sys/sdl/sdl.c sys/sdl/keymap.c
	@${REINPLACE_CMD} -e "s|SDL/|SDL11/|g" ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
