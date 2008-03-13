# ex:ts=8
# New ports collection makefile for:   	armagetron
# Date created:                        	12 November 2005
# Whom:                                 Maxime Henrion <mux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	armagetron
PORTVERSION=	0.2.7.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	armagetronad
DISTNAME=	armagetronad-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiplayer networked Tron clone in 3D

USE_GL=		yes
USE_SDL=	sdl image
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS} -I${X11BASE}/include"

LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

OPTIONS=	MUSIC	"Compile in support for background music" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MUSIC)
USE_SDL+=	mixer
CONFIGURE_ARGS+=--enable-music
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|^#!/bin/bash$$|#!/bin/sh|g' ${WRKSRC}/batch/*
	@${REINPLACE_CMD} -e 's|^INSTALL=.*$$|INSTALL=${DATADIR}|g' \
	    ${WRKSRC}/batch/*.in
	@${RM} -f ${WRKSRC}/batch/*.bak ${WRKSRC}/batch/*.orig

.include <bsd.port.post.mk>
