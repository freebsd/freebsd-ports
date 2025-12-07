PORTNAME=	libgeotiff
PORTVERSION=	1.7.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/OSGeo/libgeotiff/releases/download/${PORTVERSION}/ \
		https://download.osgeo.org/geotiff/libgeotiff/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing GeoTIFF information tags
WWW=		https://github.com/OSGeo/libgeotiff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	proj>=6,1:graphics/proj
LIB_DEPENDS=	libjbig.so:graphics/jbigkit \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff

USES=		jpeg libtool pathfix

CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--disable-doxygen-chi \
		--disable-doxygen-chm \
		--disable-doxygen-doc \
		--disable-doxygen-dot \
		--disable-doxygen-html \
		--disable-doxygen-man \
		--disable-doxygen-pdf \
		--disable-doxygen-ps \
		--disable-doxygen-rtf \
		--disable-doxygen-xml \
		--with-jpeg=${LOCALBASE} \
		--with-libtiff=${LOCALBASE} \
		--with-proj=${LOCALBASE} \
		--with-zip=/usr
CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
