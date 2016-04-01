# Created by: ijliao
# $FreeBSD$

PORTNAME=	tif22pnm
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://pts.szit.bme.hu/ \
		GOOGLE_CODE

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Converts TIFF-sampled images to PNM image

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

PROJECTHOST=	sam2p
USES=		pkgconfig

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
		&& ${CC} ${CFLAGS} -DNDEBUG `pkg-config libpng --cflags` \
		${PNG2PNM_SRCS} -o png22pnm `pkg-config libpng --libs` -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/png22pnm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tif22pnm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
