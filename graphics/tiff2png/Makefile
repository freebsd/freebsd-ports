# New ports collection makefile for:	tiff2png
# Date created:				Tue 04 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	tiff2png
PORTVERSION=	0.81
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/applications/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.4:${PORTSDIR}/graphics/png

ALL_TARGET=	tiff2png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tiff2png ${PREFIX}/bin

.include <bsd.port.mk>
