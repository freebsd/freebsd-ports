# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	intl
PORTVERSION=	3.0.0
PORTREVISION=	7
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PECL extension to support Internationalization(ICU)

LICENSE=	PHP301

LIB_DEPENDS=	libicui18n.so:devel/icu

IGNORE_WITH_PHP=70 71
USES=		php:ext tar:tgz

.include <bsd.port.mk>
