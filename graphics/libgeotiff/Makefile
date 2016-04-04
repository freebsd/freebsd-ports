# Created by: Sam Lawrance
# $FreeBSD$

PORTNAME=	libgeotiff
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/geotiff/libgeotiff/ \
		ftp://ftp.remotesensing.org/geotiff/libgeotiff/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing GeoTIFF information tags

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjbig.so:graphics/jbigkit \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff

CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--disable-doxygen-doc \
		--disable-doxygen-dot \
		--disable-doxygen-html \
		--disable-doxygen-man \
		--with-jpeg=${LOCALBASE} \
		--with-proj=${LOCALBASE} \
		--with-libtiff=${LOCALBASE} \
		--with-zlib=/usr
CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		jpeg libtool

PORTDATA=	*

.include <bsd.port.mk>
