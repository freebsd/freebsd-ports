# ex:ts=8
# Ports collection makefile for:	sam2p
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sam2p
PORTVERSION=	0.45
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.inf.bme.hu/~pts/
DISTNAME=	${PORTNAME}-latest

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts raster (bitmap) image formats into PS or PDF files

BUILD_DEPENDS=	tif22pnm:${PORTSDIR}/graphics/tif22pnm \
		tifftopnm:${PORTSDIR}/graphics/netpbm \
		zip:${PORTSDIR}/archivers/zip \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_GHOSTSCRIPT_RUN=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	bin/sam2p
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sam2p ${PREFIX}/bin

.include <bsd.port.mk>
