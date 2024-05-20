PORTNAME=	opentelemetry-instrumentation-rails
PORTVERSION=	0.30.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Rails instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/rails

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.0<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-instrumentation-action_pack>=0.9.0:devel/rubygem-opentelemetry-instrumentation-action_pack \
		rubygem-opentelemetry-instrumentation-action_view>=0.7.0<0.8:devel/rubygem-opentelemetry-instrumentation-action_view \
		rubygem-opentelemetry-instrumentation-active_job>=0.7.0<0.8:devel/rubygem-opentelemetry-instrumentation-active_job \
		rubygem-opentelemetry-instrumentation-active_record>=0.7.0<0.8:devel/rubygem-opentelemetry-instrumentation-active_record \
		rubygem-opentelemetry-instrumentation-active_support>=0.5.0<0.6:devel/rubygem-opentelemetry-instrumentation-active_support \
		rubygem-opentelemetry-instrumentation-base>=0.22.1<0.23:devel/rubygem-opentelemetry-instrumentation-base

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
