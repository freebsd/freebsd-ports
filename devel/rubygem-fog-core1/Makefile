PORTNAME=	fog-core
PORTVERSION=	1.45.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shared classes and tests for fog providers and services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-builder>=0:devel/rubygem-builder \
		rubygem-excon>=0.58<1:devel/rubygem-excon \
		rubygem-formatador>=0.2<2.0:devel/rubygem-formatador

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
