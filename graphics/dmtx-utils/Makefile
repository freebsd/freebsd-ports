# Created by: johans
# $FreeBSD$

PORTNAME=	dmtx-utils
PORTVERSION=	0.7.4
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/libdmtx/libdmtx/${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Software for reading and writing Data Matrix barcodes

LICENSE=	LGPL21+

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx \
		libMagickWand-6.so:graphics/ImageMagick \
		libMagickCore-6.so:graphics/ImageMagick

USES=		localbase tar:bzip2 pkgconfig
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/dmtxread bin/dmtxwrite bin/dmtxquery \
		man/man1/dmtxread.1.gz man/man1/dmtxwrite.1.gz \
		man/man1/dmtxquery.1.gz

.include <bsd.port.mk>
