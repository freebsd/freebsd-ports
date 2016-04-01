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
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgd.so:graphics/gd \
		libavutil.so:multimedia/ffmpeg

IGNORE_WITH_PHP=70
USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHPIZE=	yes
USES=		localbase tar:xz

.include <bsd.port.mk>
