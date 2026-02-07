PORTNAME=	opentelemetry-instrumentation-active_model_serializers
PORTVERSION=	0.24.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Active Model Serializers instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/active_model_serializers \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-active_support>=0.7.0:devel/rubygem-opentelemetry-instrumentation-active_support

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
