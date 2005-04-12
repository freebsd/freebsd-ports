# ex:ts=8
# Ports collection makefile for:	tif22pnm
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tif22pnm
PORTVERSION=	0.11
CATEGORIES=	graphics
MASTER_SITES=	http://www.inf.bme.hu/~pts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts TIFF- sampled images to PNM image

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libtiff-ldir=${LOCALBASE}/lib \
		--with-libtiff-idir=${LOCALBASE}/include

PLIST_FILES=	bin/png22pnm bin/tif22pnm

post-patch:
	@${REINPLACE_CMD} -e 's| -O2| ${CFLAGS}|g' ${WRKSRC}/do.sh

do-build:
	@(cd ${WRKSRC} ; ${LOCALBASE}/bin/bash do.sh compile)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/png22pnm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tif22pnm ${PREFIX}/bin

.include <bsd.port.mk>
