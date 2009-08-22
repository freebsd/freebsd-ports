# ex:ts=8
# New ports collection makefile for:   	armagetron
# Date created:                        	12 November 2005
# Whom:                                 Maxime Henrion <mux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	armagetron
PORTVERSION=	0.2.8.2.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}ad/${PORTNAME}ad-src/${PORTVERSION}
DISTNAME=	armagetronad-${PORTVERSION}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ianthetechie@gmail.com
COMMENT=	A multiplayer networked Tron clone in 3D

USE_GL=		gl
USE_SDL=	sdl image
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS} -I${LOCALBASE}/include `${SDL_CONFIG} --cflags`"
CONFIGURE_ARGS=	--disable-etc

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		xml2.5:${PORTSDIR}/textproc/libxml2

OPTIONS=	MUSIC	"Compile in support for background music" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MUSIC)
USE_SDL+=	mixer
CONFIGURE_ARGS+=--enable-music
.endif

# This script isn't needed and only causes install problems
CONFIGURE_ARGS+=--disable-uninstall 

post-patch:
	@${REINPLACE_CMD} -e 's|sdl11-config|${SDL_CONFIG}|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/batch -type f -exec ${REINPLACE_CMD} -e 's|^#!/bin/bash$$|#!/bin/sh|g' {} \+
	@${REINPLACE_CMD} -e 's|^INSTALL=.*$$|INSTALL=${DATADIR}|g' \
	    ${WRKSRC}/batch/*.in
	@${FIND} ${WRKSRC}/batch -name '*.bak' -o -name '*.orig' -delete

.include <bsd.port.post.mk>
