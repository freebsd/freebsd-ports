# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	facedetect
PORTVERSION=	1.1
PORTREVISION=	10
CATEGORIES=	graphics
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Face detection extension for PHP using OpenCV library

LICENSE=	PHP30

LIB_DEPENDS=	libopencv_objdetect.so:graphics/opencv

USE_GITHUB=	yes
GH_ACCOUNT=	infusion
GH_PROJECT=	PHP-Facedetect
GH_TAGNAME=	2a8974b

LIBS+=		-lopencv_core

USES=		localbase php:ext pkgconfig

CONFIGURE_ARGS+=	--with-facedetect

.include <bsd.port.mk>
