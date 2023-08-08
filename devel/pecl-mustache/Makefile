PORTNAME=	mustache
PORTVERSION=	0.9.3
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mustache templating language
WWW=		https://pecl.php.net/package/mustache \
		https://github.com/jbboehr/php-mustache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libmustache.so:devel/libmustache

USES=		compiler:c++11-lang php:pecl

USE_CXXSTD=	c++11

.include <bsd.port.mk>
