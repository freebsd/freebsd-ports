# ex:ts=8
# Ports collection makefile for:	tif22pnm
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tif22pnm
PORTVERSION=	0.10
CATEGORIES=	graphics
MASTER_SITES=	http://www.inf.bme.hu/~pts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts TIFF- sampled images to PNM image

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff

PLIST_FILES=	bin/tif22pnm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libtiff-ldir=${LOCALBASE}/lib \
		--with-libtiff-idir=${LOCALBASE}/include

do-build:
	@(cd ${WRKSRC} ; ${LOCALBASE}/bin/bash do.sh compile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tif22pnm ${PREFIX}/bin

.include <bsd.port.mk>
