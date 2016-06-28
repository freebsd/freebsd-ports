# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fribidi
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	converters pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PECL extension for the Unicode Bidi algorithm

LIB_DEPENDS=	libfribidi.so:converters/fribidi

USES=		php:ext pkgconfig tar:tgz
IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--with-fribidi=${LOCALBASE}

.include <bsd.port.mk>
