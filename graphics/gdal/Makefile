# New ports collection makefile for:	Geospatial Data Abstraction Library
# Date created:		27 Aug 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.1.7
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/gdal/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen

USE_PYTHON=     yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-libz=internal \
		--with-png=internal \
		--with-libtiff=internal \
		--with-libgeotiff=internal \
		--with-libjpeg=internal \
		--with-libgif=internal \
		--with-python
MAKEFILE=	GNUmakefile
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
