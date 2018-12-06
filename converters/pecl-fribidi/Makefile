# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fribidi
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	converters pear

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PECL extension for the Unicode Bidi algorithm

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LIB_DEPENDS=	libfribidi.so:converters/fribidi

USES=		php:pecl pkgconfig
IGNORE_WITH_PHP=	71 72 73

CONFIGURE_ARGS=	--with-fribidi=${LOCALBASE}

.include <bsd.port.mk>
