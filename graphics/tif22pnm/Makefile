# ex:ts=8
# Ports collection makefile for:	tif22pnm
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tif22pnm
PORTVERSION=	0.12
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://pts.szit.bme.hu/ \
		GOOGLE_CODE

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Converts TIFF-sampled images to PNM image

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

PROJECTHOST=	sam2p
USE_PKGCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libtiff-ldir=${LOCALBASE}/lib \
		--with-libtiff-idir=${LOCALBASE}/include

PLIST_FILES=	bin/png22pnm bin/tif22pnm

TIF22PNM_SRCS=	ptspnm.c minigimp.c miniglib.c ptstiff3.c tif22pnm.c
PNG2PNM_SRCS=	png22pnm.c

do-build:
	cd ${WRKSRC} \
		&& ${CC} ${CFLAGS} -DNDEBUG -I${LOCALBASE}/include \
		${TIF22PNM_SRCS} -o tif22pnm -L${LOCALBASE}/lib -ltiff \
		&& ${CC} ${CFLAGS} -DNDEBUG `pkg-config libpng15 --cflags` \
		${PNG2PNM_SRCS} -o png22pnm `pkg-config libpng15 --libs`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/png22pnm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tif22pnm ${PREFIX}/bin

.include <bsd.port.mk>
