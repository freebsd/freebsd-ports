# Created by: johans
# $FreeBSD$

PORTNAME=	dmtx-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.6
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Software for reading and writing Data Matrix barcodes

LICENSE=	LGPL21+

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libMagickWand-${IMAGEMAGICK_DEFAULT}.so:graphics/ImageMagick${IMAGEMAGICK_DEFAULT}

USES=		autoreconf libtool localbase tar:bzip2 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	dmtx

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/dmtxread bin/dmtxwrite bin/dmtxquery \
		man/man1/dmtxread.1.gz man/man1/dmtxwrite.1.gz \
		man/man1/dmtxquery.1.gz

.include <bsd.port.mk>
