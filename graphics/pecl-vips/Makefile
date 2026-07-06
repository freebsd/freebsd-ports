PORTNAME=	vips
PORTVERSION=	1.0.13
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	mops@punkt.de
COMMENT=	PHP bindings for libvips
WWW=		https://github.com/libvips/php-vips-ext

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libvips.so:graphics/vips

USES=		compiler:c11 php:pecl pkgconfig
IGNORE_WITH_PHP=	86

.include <bsd.port.mk>
