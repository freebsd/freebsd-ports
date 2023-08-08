PORTNAME=	facedetect
PORTVERSION=	1.1
PORTREVISION=	15
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Face detection extension for PHP using OpenCV library
WWW=		https://www.xarg.org/project/php-facedetect/

LICENSE=	PHP30

DEPRECATED=	Requires php80 which is set to expire on 2023-11-26
EXPIRATION_DATE=	2023-12-31

LIB_DEPENDS=	libopencv_objdetect.so:graphics/opencv

USE_GITHUB=	yes
GH_ACCOUNT=	infusion
GH_PROJECT=	PHP-Facedetect
GH_TAGNAME=	2a8974b

LIBS+=		-lopencv_core

USES=		compiler:c11 localbase php:ext pkgconfig
IGNORE_WITH_PHP=	81 82 83

CONFIGURE_ARGS+=	--with-facedetect

.include <bsd.port.mk>
