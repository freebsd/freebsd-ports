# New ports collection makefile for:	libdmtx
# Date created:				16 April 2009
# Whom:					johans
#
# $FreeBSD$
#

PORTNAME=	libdmtx
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Software for reading and writing Data Matrix barcodes

LIB_DEPENDS=	MagickWand.4:${PORTSDIR}/graphics/ImageMagick

MAN1=		dmtxread.1 dmtxwrite.1 dmtxquery.1
MAN3=		libdmtx.3

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e '/^pkgconfigdir /s:(libdir):{prefix}/libdata:' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
