# New ports collection makefile for:	dc20ctrl
# Date created:		17 Feb 1998
# Whom:			Ugo Paternostro <paterno@dsi.unifi.it>
#
# $FreeBSD$
#

PORTNAME=	dc20ctrl
PORTVERSION=	0.4
CATEGORIES=	graphics
MASTER_SITES=   http://aguirre.dsi.unifi.it/~paterno/binaries/

MAINTAINER=	paterno@dsi.unifi.it

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.3:${PORTSDIR}/graphics/png

MAKE_FLAGS=	-DUSE_JPEG -DUSE_TIFF -DUSE_PNG

MAN1=		dc20ctrl.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
