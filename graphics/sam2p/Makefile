# ex:ts=8
# Ports collection makefile for:	sam2p
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sam2p
PORTVERSION=	0.44
CATEGORIES=	graphics
MASTER_SITES=	http://www.inf.bme.hu/~pts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts raster (bitmap) image formats into PS or PDF files

.if defined(WITH_GHOSTSCRIPT_AFPL) && ${WITH_GHOSTSCRIPT_AFPL} == yes
GSPORT?=	print/ghostscript-afpl
.else
GSPORT?=	print/ghostscript-gnu
.endif

BUILD_DEPENDS=	tif22pnm:${PORTSDIR}/graphics/tif22pnm \
		tifftopnm:${PORTSDIR}/graphics/netpbm \
		gs:${PORTSDIR}/${GSPORT} \
		zip:${PORTSDIR}/archivers/zip \
		bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sam2p ${PREFIX}/bin

.include <bsd.port.mk>
