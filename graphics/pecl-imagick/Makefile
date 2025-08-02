PORTNAME=	imagick
DISTVERSION=	3.8.0
CATEGORIES=	graphics

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	PHP wrapper to the ImageMagick/GraphicsMagick library
WWW=		https://pecl.php.net/package/imagick

LICENSE=	PHP301

USES=		cpe localbase magick php:pecl

CPE_VENDOR=	php

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.pre.mk>

post-patch:
.if ${PHP_VER} >= 85
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string|Zend/zend_smart_string|' \
		${WRKSRC}/imagick.c
.endif

.include <bsd.port.post.mk>
