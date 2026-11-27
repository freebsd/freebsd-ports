PORTNAME=	opentelemetry-instrumentation-base
PORTVERSION=	0.27.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Instrumentation Base for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/base \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	Apache-2.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api-gitlab>=1.7<2:devel/rubygem-opentelemetry-api-gitlab \
		rubygem-opentelemetry-common-gitlab>=0.21<1:devel/rubygem-opentelemetry-common-gitlab \
		rubygem-opentelemetry-logs-api-gitlab>=0.6<1:devel/rubygem-opentelemetry-logs-api-gitlab \
		rubygem-opentelemetry-metrics-api-gitlab>=0.9<1:devel/rubygem-opentelemetry-metrics-api-gitlab \
		rubygem-opentelemetry-registry-gitlab>=0.1<1:devel/rubygem-opentelemetry-registry-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
