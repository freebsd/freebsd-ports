# New ports collection makefile for:   panorama-tools
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#

PORTNAME=	hugin
PORTVERSION=	0.4.r1
CATEGORIES=	graphics
MASTER_SITES=	http://www.openit.com.br/distfiles/
DISTNAME=	${PORTNAME}-0.4pre_src

MAINTAINER=	cartola@openit.com.br
COMMENT=	An easy to use cross-platform GUI for Panorama Tools

BUILD_DEPENDS=	PTOptimizer:${PORTSDIR}/graphics/libpano12 \
		vigra-config:${PORTSDIR}/graphics/vigra
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		fftw:${PORTSDIR}/math/fftw \
		wx_gtk2:${PORTSDIR}/x11-toolkits/wxgtk2 \
		wx_gtk2_xrc:${PORTSDIR}/x11-toolkits/wxgtk2-contrib
RUN_DEPENDS=	PTOptimizer:${PORTSDIR}/graphics/libpano12 \
		PTStitcher:${PORTSDIR}/graphics/linux-panorama-tools

WRKSRC=		${WRKDIR}/hugin
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

DOCSDIR=        ${PREFIX}/share/hugin/xrc/data

.include <bsd.port.mk>
