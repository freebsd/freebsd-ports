PORTNAME=	datadog-ci
PORTVERSION=	1.21.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Datadog's Test Optimization library for Ruby
WWW=		https://docs.datadoghq.com/continuous_integration/ \
		https://github.com/DataDog/datadog-ci-rb

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.BSD3

RUN_DEPENDS=	rubygem-datadog>=2.4<3:devel/rubygem-datadog \
		rubygem-drb>=0:devel/rubygem-drb \
		rubygem-msgpack>=0:devel/rubygem-msgpack

USES=		gem

PLIST_FILES=	bin/ddcirb

.include <bsd.port.mk>
