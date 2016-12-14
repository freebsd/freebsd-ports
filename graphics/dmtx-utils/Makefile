# Created by: johans
# $FreeBSD$

PORTNAME=	dmtx-utils
PORTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/libdmtx/libdmtx/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Software for reading and writing Data Matrix barcodes

LIB_DEPENDS=	libdmtx.so:graphics/libdmtx

USES=		tar:bzip2 pkgconfig
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/dmtxread bin/dmtxwrite bin/dmtxquery \
		man/man1/dmtxread.1.gz man/man1/dmtxwrite.1.gz \
		man/man1/dmtxquery.1.gz

.include <bsd.port.mk>
