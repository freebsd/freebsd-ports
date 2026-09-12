PORTNAME=	mustache
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mustache templating language
WWW=		https://github.com/jbboehr/php-mustache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libmustache.so:devel/libmustache

USES=		compiler:c++17-lang php:ext

USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	jbboehr
GH_PROJECT=	php-mustache

.include <bsd.port.mk>
