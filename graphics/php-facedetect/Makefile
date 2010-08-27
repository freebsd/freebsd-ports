# New ports collection makefile for:	php5-facedetect
# Date created:		2010-03-26
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	facedetect
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.xarg.org/download/
PKGNAMEPREFIX=	php-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Face detection extension for PHP using OpenCV library

LIB_DEPENDS=	cv.2:${PORTSDIR}/graphics/opencv

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

CONFIGURE_ARGS+=	--with-facedetect
CONFIGURE_ENV+=		LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
USE_GCC=	4.2+
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/cvconfig.h

.include <bsd.port.post.mk>
