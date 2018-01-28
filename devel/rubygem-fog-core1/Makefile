# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-core
PORTVERSION=	1.45.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shared classes and tests for fog providers and services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-excon>=0.58:devel/rubygem-excon \
		rubygem-formatador>=0.2:devel/rubygem-formatador

PORTSCOUT=	limit:^1\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
