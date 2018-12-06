# Created by: Wen Heping<wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tokyo_tyrant
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	databases pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Wrapper to the Tokyo Tyrant client library

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtokyotyrant.so:databases/tokyotyrant

USES=		php:pecl pkgconfig
USE_PHP=	session:build
IGNORE_WITH_PHP=	71 72 73

.include <bsd.port.mk>
