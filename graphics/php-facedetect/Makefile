# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	facedetect
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/infusion/PHP-Facedetect/tarball/${GITVERSION}/
PKGNAMEPREFIX=	php-
DISTNAME=	infusion-PHP-Facedetect-${GITVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Face detection extension for PHP using OpenCV library

LICENSE=	PHP30

LIB_DEPENDS=	libopencv_objdetect.so:${PORTSDIR}/graphics/opencv

GITVERSION=	4b1dfe1

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LIBS+=		-lopencv_core

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-facedetect
CONFIGURE_ENV+=		LIBS="${LIBS}"

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
