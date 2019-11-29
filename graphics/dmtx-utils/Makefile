# Created by: johans
# $FreeBSD$

PORTNAME=	dmtx-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.6
CATEGORIES=	graphics

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Software for reading and writing Data Matrix barcodes

LICENSE=	LGPL21+

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libMagickWand-7.so:graphics/ImageMagick7 \
		libMagickCore-7.so:graphics/ImageMagick7

USES=		autoreconf libtool localbase tar:bzip2 pkgconfig

USE_GITHUB=	YES
GH_ACCOUNT=	dmtx

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/dmtxread bin/dmtxwrite bin/dmtxquery \
		man/man1/dmtxread.1.gz man/man1/dmtxwrite.1.gz \
		man/man1/dmtxquery.1.gz

.include <bsd.port.mk>
