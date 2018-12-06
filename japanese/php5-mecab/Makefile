# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	https://github.com/downloads/rsky/php-${PORTNAME}/
DISTNAME=	php-mecab-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	PHP5 extension for MeCab Morphological Analyzer

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LIB_DEPENDS=	libmecab.so:japanese/mecab

USES=		php:ext
IGNORE_WITH_PHP=	71 72 73
CONFIGURE_ARGS=	--with-mecab=${LOCALBASE}/bin/mecab-config

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${PHP_PKGNAMEPREFIX}

.include <bsd.port.post.mk>
