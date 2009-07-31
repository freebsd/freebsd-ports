# New ports collection makefile for:	libdmtx
# Date created:				16 April 2009
# Whom:					johans
#
# $FreeBSD$
#

PORTNAME=	libdmtx
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	johans@stack.nl
COMMENT=	Software for reading and writing Data Matrix barcodes

LIB_DEPENDS=	MagickWand.2:${PORTSDIR}/graphics/ImageMagick

MAN1=		dmtxread.1 dmtxwrite.1 dmtxquery.1
MAN3=		libdmtx.3

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
