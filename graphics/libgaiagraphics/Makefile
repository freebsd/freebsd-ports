# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	libgaiagraphics
PORTVERSION=	0.5
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Library supporting common-utility raster handling methods

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libgeotiff.so:${PORTSDIR}/graphics/libgeotiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libcairo.so:${PORTSDIR}/graphics/cairo

USES=		gmake iconv pathfix pkgconfig
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
