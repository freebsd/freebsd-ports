# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	facedetect
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	graphics
PKGNAMEPREFIX=	php-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Face detection extension for PHP using OpenCV library

LICENSE=	PHP30

LIB_DEPENDS=	libopencv_objdetect.so:graphics/opencv

USE_GITHUB=	yes
GH_ACCOUNT=	infusion
GH_PROJECT=	PHP-Facedetect
GH_TAGNAME=	4b1dfe1

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lopencv_core

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-facedetect

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
USE_GCC=	any
.endif

.include <bsd.port.post.mk>
