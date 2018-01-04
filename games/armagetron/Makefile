# Created by: Maxime Henrion <mux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	armagetron
PORTVERSION=	0.2.8.3.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}ad/stable/${PORTVERSION}/
DISTNAME=	armagetronad-${PORTVERSION}
EXTRACT_SUFX=	.src.tar.bz2

MAINTAINER=	ianthetechie@gmail.com
COMMENT=	Multiplayer networked Tron clone in 3D

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_12_aarch64=	network/nNetObject.cpp:1533:46: error: ordered comparison between pointer and zero ('const nSocket *' and 'int')
BROKEN_FreeBSD_12_armv6=	network/nNetObject.cpp:1533:46: error: ordered comparison between pointer and zero ('const nSocket *' and 'int')
BROKEN_FreeBSD_12_armv7=	network/nNetObject.cpp:1533:46: error: ordered comparison between pointer and zero ('const nSocket *' and 'int')

USES=		gmake jpeg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-etc --disable-initscripts
CXXFLAGS+=	${CFLAGS} -I${LOCALBASE}/include

BUILD_DEPENDS+=	bash:shells/bash
LIB_DEPENDS+=	libpng.so:graphics/png \
		libxml2.so:textproc/libxml2

OPTIONS_DEFINE=	MUSIC ARMA_SERVER_ONLY
MUSIC_DESC=	Compile in support for background music
ARMA_SERVER_ONLY_DESC=	Build dedicated server only

OPTIONS_DEFAULT=	MUSIC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARMA_SERVER_ONLY}
CONFIGURE_ARGS+=	--disable-glout
PLIST_SUB+=	CLIENT="@comment " SERVER="" SUFFIX="-dedicated"
PKGNAMESUFFX=	-dedicated
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
