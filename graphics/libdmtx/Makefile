# Created by: johans
# $FreeBSD$

PORTNAME=	libdmtx
PORTVERSION=	0.7.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Library for reading and writing Data Matrix barcodes

LIB_DEPENDS=	MagickWand:${PORTSDIR}/graphics/ImageMagick

MAN3=		libdmtx.3

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e '/^pkgconfigdir /s:(libdir):{prefix}/libdata:' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
