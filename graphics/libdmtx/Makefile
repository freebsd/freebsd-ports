# Created by: johans
# $FreeBSD$

PORTNAME=	libdmtx
PORTVERSION=	0.7.4
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Library for reading and writing Data Matrix barcodes

LIB_DEPENDS=	libMagickWand-6.Q16.so:${PORTSDIR}/graphics/ImageMagick

USES=		tar:bzip2 libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^pkgconfigdir /s:(libdir):{prefix}/libdata:' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
