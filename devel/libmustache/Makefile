# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmustache
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	devel
#MASTER_SITES=	

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ implementation of Mustache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libjson-c.so:devel/json-c \
		libyaml.so:textproc/libyaml

USES=		cmake compiler:c++11-lang localbase

USE_CXXSTD=	c++11

GH_ACCOUNT=	jbboehr
USE_GITHUB=	yes

.include <bsd.port.mk>
