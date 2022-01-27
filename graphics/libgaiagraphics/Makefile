# Created by: lbartoletti <lbartoletti@FreeBSD.org>

PORTNAME=	libgaiagraphics
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	graphics geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Library supporting common-utility raster handling methods

DEPRECATED=	Abandoned upstream, replaced by graphics/librasterlite2
EXPIRATION_DATE=2022-02-27
BROKEN=		fails to configure: unable to find libproj

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libgeotiff.so:graphics/libgeotiff \
		libcairo.so:graphics/cairo

USES=		gmake iconv jpeg pathfix pkgconfig libtool
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
