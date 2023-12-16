PORTNAME=	facedetect
PORTVERSION=	1.1
PORTREVISION=	16
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Face detection extension for PHP using OpenCV library
WWW=		https://www.xarg.org/project/php-facedetect/

LICENSE=	PHP30

LIB_DEPENDS=	libopencv_objdetect.so:graphics/opencv

USE_GITHUB=	yes
GH_ACCOUNT=	infusion
GH_PROJECT=	PHP-Facedetect
GH_TAGNAME=	0e243c5

LIBS+=		-lopencv_core

USES=		compiler:c11 localbase php:ext pkgconfig
IGNORE_WITH_PHP=	82 83

CONFIGURE_ARGS+=	--with-facedetect

.include <bsd.port.mk>
