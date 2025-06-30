PORTNAME=	spatialite
PORTVERSION=	5.1.0
PORTREVISION=	4
CATEGORIES=	databases geography
MASTER_SITES=	http://www.gaia-gis.it/gaia-sins/libspatialite-sources/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Spatial Extensions for SQLite
WWW=		https://www.gaia-gis.it/gaia-sins/

LICENSE=	GPLv2 # Only GPLv2 since we enable rttopo and gcp
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgeos_c.so:graphics/geos \
		libproj.so:graphics/proj \
		libfreexl.so:textproc/freexl \
		librttopo.so:devel/librttopo

GNU_CONFIGURE=	yes
USES=		gmake gnome iconv libtool pathfix minizip pkgconfig sqlite
USE_GNOME=	libxml2

CFLAGS+=	-I${WRKSRC}/src/headers -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS+=	--enable-gcp=yes --enable-libxml2=yes --enable-rttopo=yes \
			CFLAGS="${CFLAGS}" \
			LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
INSTALL_TARGET=install-strip

#post-patch:
#	@${REINPLACE_CMD} -e 's|-ldl| |' ${WRKSRC}/configure

.include <bsd.port.mk>
