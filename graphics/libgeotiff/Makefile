# New ports collection makefile for:		libgeotiff
# Date created:					9 December 2005
# Whom:						Sam Lawrance
#
# $FreeBSD$
#

PORTNAME=	libgeotiff
PORTVERSION=	1.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/geotiff/libgeotiff/ \
		ftp://ftp.remotesensing.org/geotiff/libgeotiff/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Library for reading and writing GeoTIFF information tags

LIB_DEPENDS=	jbig:${PORTSDIR}/graphics/jbigkit \
		jpeg:${PORTSDIR}/graphics/jpeg \
		proj:${PORTSDIR}/graphics/proj \
		tiff:${PORTSDIR}/graphics/tiff

CONFIGURE_ARGS=	--disable-doxygen-doc \
		--disable-doxygen-dot \
		--disable-doxygen-html \
		--disable-doxygen-man \
		--with-jpeg=${LOCALBASE} \
		--with-proj=${LOCALBASE} \
		--with-libtiff=${LOCALBASE} \
		--with-zlib=/usr
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
