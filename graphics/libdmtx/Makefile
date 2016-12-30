# Created by: johans
# $FreeBSD$

PORTNAME=	libdmtx
PORTVERSION=	0.7.4
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Library for reading and writing Data Matrix barcodes

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libMagickWand-6.so:graphics/ImageMagick

USES=		tar:bzip2 libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
