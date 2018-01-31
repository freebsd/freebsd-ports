# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-json
PORTVERSION=	1.0.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	102

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Extraction of the JSON parsing tools between providers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core1>=1:devel/rubygem-fog-core1 \
		rubygem-multi_json>=1.10:devel/rubygem-multi_json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes
PORTSCOUT=	limit:^1\.0\.

.include <bsd.port.mk>
