# Created by: Sam Lawrance
# $FreeBSD$

PORTNAME=	libgeotiff
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/geotiff/libgeotiff/ \
		ftp://ftp.remotesensing.org/geotiff/libgeotiff/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for reading and writing GeoTIFF information tags

LIB_DEPENDS=	libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libproj.so:${PORTSDIR}/graphics/proj \
		libtiff.so:${PORTSDIR}/graphics/tiff

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
USE_LDCONFIG=	yes

.include <bsd.port.mk>
