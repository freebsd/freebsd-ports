# New ports collection makefile for:   hugin
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
#

PORTNAME=	hugin
PORTVERSION=	0.5.b2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.5-beta2

MAINTAINER=	cartola@openit.com.br
COMMENT=	A GUI for Panorama Tools, to stitch panoramic images

BUILD_DEPENDS=	PTOptimizer:${PORTSDIR}/graphics/libpano12 \
		vigra-config:${PORTSDIR}/graphics/vigra
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		fftw:${PORTSDIR}/math/fftw \
		wx_gtk2:${PORTSDIR}/x11-toolkits/wxgtk24 \
		wx_gtk2_xrc:${PORTSDIR}/x11-toolkits/wxgtk24-contrib \
		boost_date_time:${PORTSDIR}/devel/boost
RUN_DEPENDS=	PTOptimizer:${PORTSDIR}/graphics/libpano12 \
		PTStitcher:${PORTSDIR}/graphics/linux-panorama-tools

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_BZIP2=	yes

DOCSDIR=	${PREFIX}/share/hugin/xrc/data

.include <bsd.port.mk>
