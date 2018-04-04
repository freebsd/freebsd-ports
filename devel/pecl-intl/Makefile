# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	intl
PORTVERSION=	3.0.0
PORTREVISION=	12
CATEGORIES=	devel pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PECL extension to support Internationalization(ICU)

LICENSE=	PHP301

LIB_DEPENDS=	libicui18n.so:devel/icu

IGNORE_WITH_PHP=70 71 72
USES=		compiler:c++11-lib php:pecl
USE_CXXSTD=	gnu++11

CPPFLAGS+=	-DU_USING_ICU_NAMESPACE=1

.include <bsd.port.mk>
