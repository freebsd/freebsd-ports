# Created by: Maxime Henrion <mux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	armagetron
PORTVERSION=	0.2.8.2.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}ad/${PORTNAME}ad-src/${PORTVERSION}
DISTNAME=	armagetronad-${PORTVERSION}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ianthetechie@gmail.com
COMMENT=	A multiplayer networked Tron clone in 3D

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-etc --disable-initscripts
CXXFLAGS+=	${CFLAGS} -I${LOCALBASE}/include

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		xml2.5:${PORTSDIR}/textproc/libxml2

OPTIONS_DEFINE=	MUSIC ARMA_SERVER_ONLY
MUSIC_DESC=	Compile in support for background music
ARMA_SERVER_ONLY_DESC=	Build dedicated server only

OPTIONS_DEFAULT=	MUSIC

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARMA_SERVER_ONLY}
CONFIGURE_ARGS+=	--disable-glout
PLIST_SUB+=	CLIENT="@comment " SERVER="" SUFFIX="-dedicated"
PKGNAMESUFFX=	-dedicated
USE_RC_SUBR=	armagetronad_dedicated
.else
USE_GL=		gl
USE_SDL=	sdl image
CXXFLAGS+=	`${SDL_CONFIG} --cflags`
PLIST_SUB+=	CLIENT="" SERVER="@comment " SUFFIX=""
.if ${PORT_OPTIONS:MMUSIC}
USE_SDL+=	mixer
CONFIGURE_ARGS+=--enable-music
.endif
.endif

# This script isn't needed and only causes install problems
CONFIGURE_ARGS+=--disable-uninstall

post-patch:
	@${REINPLACE_CMD} -e 's|sdl11-config|${SDL_CONFIG}|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/batch -type f -exec ${REINPLACE_CMD} -e 's|^#!/bin/bash$$|#!/bin/sh|g' {} \+
	@${REINPLACE_CMD} -e 's|^INSTALL=.*$$|INSTALL=${DATADIR}|g' \
	    ${WRKSRC}/batch/*.in
	@${FIND} ${WRKSRC}/batch -name '*.bak' -o -name '*.orig' -delete

.include <bsd.port.mk>
