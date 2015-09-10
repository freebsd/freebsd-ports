# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	0.6.0.20120114
DISTVERSIONPREFIX=	php-
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/sunpoet
PKGNAMEPREFIX=	php5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	FFmpeg shared extension for php

LICENSE=	GPLv2

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd \
		libavutil.so:${PORTSDIR}/multimedia/ffmpeg

CFLAGS+=	-I${LOCALBASE}/include
USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USES=		tar:xz

.include <bsd.port.mk>
