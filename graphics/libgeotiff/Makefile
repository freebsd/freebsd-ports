# New ports collection makefile for:		libgeotiff
# Date created:					9 December 2005
# Whom:						Sam Lawrance
#
# $FreeBSD$
#

PORTNAME=	libgeotiff
PORTVERSION=	1.2.5
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/geotiff/libgeotiff/ \
		ftp://ftp.remotesensing.org/geotiff/libgeotiff/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Library for reading and writing GeoTIFF information tags

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		proj.6:${PORTSDIR}/graphics/proj \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GNOME=	gnometarget
USE_AUTOTOOLS=	automake:15:env autoconf:262:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-jpeg=${LOCALBASE} \
		--with-proj=${LOCALBASE} \
		--with-libtiff=${LOCALBASE}
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
