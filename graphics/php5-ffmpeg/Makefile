# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ffmpeg
PORTVERSION=	0.6.0.20120114
DISTVERSIONPREFIX=	php-
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	LOCAL/sunpoet
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	FFmpeg shared extension for php

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgd.so:graphics/gd \
		libavutil.so:multimedia/ffmpeg

IGNORE_WITH_PHP=71 72 73
USES=		localbase php:ext tar:xz

.include <bsd.port.mk>
