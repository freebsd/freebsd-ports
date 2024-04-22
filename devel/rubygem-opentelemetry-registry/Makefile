PORTNAME=	opentelemetry-registry
PORTVERSION=	0.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Registry for the OpenTelemetry Instrumentation libraries
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/registry

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.1<2:devel/rubygem-opentelemetry-api

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
