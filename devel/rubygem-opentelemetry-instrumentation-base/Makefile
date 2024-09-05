PORTNAME=	opentelemetry-instrumentation-base
PORTVERSION=	0.22.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Instrumentation Base for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/base

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.0<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-common>=0.21<1:devel/rubygem-opentelemetry-common \
		rubygem-opentelemetry-registry>=0.1<1:devel/rubygem-opentelemetry-registry

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
