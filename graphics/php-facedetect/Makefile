# New ports collection makefile for:	php5-facedetect
# Date created:		2010-03-26
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	facedetect
PORTVERSION=	1.1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/infusion/PHP-Facedetect/tarball/${GITVERSION}/
PKGNAMEPREFIX=	php-
DISTNAME=	infusion-PHP-Facedetect-${GITVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Face detection extension for PHP using OpenCV library

LIB_DEPENDS=	opencv_legacy.2:${PORTSDIR}/graphics/opencv

LICENSE=	PHP30

GITVERSION=	75a1d8f
FETCH_ARGS=	-pRr

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS+=	--with-facedetect

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
USE_GCC=	4.2+
.endif

.include <bsd.port.post.mk>
