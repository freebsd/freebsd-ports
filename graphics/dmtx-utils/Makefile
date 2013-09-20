# Created by: johans
# $FreeBSD$

PORTNAME=	dmtx-utils
PORTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=libdmtx/libdmtx/${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Software for reading and writing Data Matrix barcodes

LIB_DEPENDS=	dmtx.0:${PORTSDIR}/graphics/libdmtx

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAN1=		dmtxread.1 dmtxwrite.1 dmtxquery.1
PLIST_FILES=	bin/dmtxread bin/dmtxwrite bin/dmtxquery

NO_STAGE=	yes
.include <bsd.port.mk>
