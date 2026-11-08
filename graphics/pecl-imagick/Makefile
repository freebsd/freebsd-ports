PORTNAME=	imagick
DISTVERSION=	3.8.1
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	PHP wrapper to the ImageMagick/GraphicsMagick library
WWW=		https://pecl.php.net/package/imagick

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe localbase magick php:pecl

CPE_VENDOR=	php

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

.include <bsd.port.pre.mk>

post-patch:
.if ${PHP_VER} >= 86
	@${REINPLACE_CMD} -e 's|XtOffsetOf|offsetof|' \
			-e 's|zval_dtor|zval_ptr_dtor_nogc|' \
		${WRKSRC}/imagick.c \
		${WRKSRC}/imagick_helpers.c \
		${WRKSRC}/php_imagick_defs.h
.endif

.include <bsd.port.post.mk>
