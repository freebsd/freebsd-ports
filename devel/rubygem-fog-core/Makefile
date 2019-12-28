# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-core
PORTVERSION=	2.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shared classes and tests for fog providers and services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-excon>=0.71<1:devel/rubygem-excon \
		rubygem-formatador>=0.2<1:devel/rubygem-formatador \
		rubygem-mime-types>=0:misc/rubygem-mime-types

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
