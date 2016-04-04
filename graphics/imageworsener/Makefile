# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	imageworsener
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://entropymine.com/imageworsener/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CLI utility and library for image scaling and processing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.txt

OPTIONS_DEFINE=	JPEG PNG WEBP
OPTIONS_DEFAULT=JPEG PNG WEBP

CONFIGURE_ARGS=	--with-zlib-include-dir=${INCLUDEDIR} \
		--with-zlib-lib-dir=${LIBDIR}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool

JPEG_CONFIGURE_WITH=	jpeg
JPEG_USES=		jpeg
PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng.so:graphics/png
WEBP_CONFIGURE_WITH=	webp
WEBP_LIB_DEPENDS=	libwebp.so:graphics/webp

.include <bsd.port.mk>
