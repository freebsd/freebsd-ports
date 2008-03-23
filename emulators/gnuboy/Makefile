# ex:ts=8
# New ports collection makefile for:	gnuboy
# Date created:			Mar 11, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnuboy
PORTVERSION=	1.0.3
PORTREVISION=	7
CATEGORIES=	emulators games
MASTER_SITES=	http://gnuboy.unix-fu.org/src/ \
		http://brightrain.aerifal.cx/~laguna/src/

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	Nintendo GameBoy emulator

LIB_DEPENDS=	vga.1:${PORTSDIR}/graphics/svgalib

USE_SDL=	sdl
USE_XORG=	x11
USE_AUTOTOOLS=	autoconf:261
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-sdl

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	bin/sdlgnuboy bin/sgnuboy bin/xgnuboy

post-patch:

do-install:
.for file in sdlgnuboy sgnuboy xgnuboy
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
