# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mustache
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Mustache templating language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libmustache.so:devel/libmustache

USES=		compiler:c++11-lang php:pecl
IGNORE_WITH_PHP=	74

USE_CXXSTD=	c++11

post-patch:
	@${REINPLACE_CMD} -e '/stdc++/d' ${WRKSRC}/config.m4

.include <bsd.port.mk>
