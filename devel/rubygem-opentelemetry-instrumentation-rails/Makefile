PORTNAME=	opentelemetry-instrumentation-rails
PORTVERSION=	0.37.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Rails instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/rails \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.0<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-instrumentation-action_mailer>=0.4.0<0.5:devel/rubygem-opentelemetry-instrumentation-action_mailer \
		rubygem-opentelemetry-instrumentation-action_pack>=0.13.0<0.14:devel/rubygem-opentelemetry-instrumentation-action_pack \
		rubygem-opentelemetry-instrumentation-action_view>=0.9.0<0.10:devel/rubygem-opentelemetry-instrumentation-action_view \
		rubygem-opentelemetry-instrumentation-active_job>=0.8.0<0.9:devel/rubygem-opentelemetry-instrumentation-active_job \
		rubygem-opentelemetry-instrumentation-active_record>=0.9.0<0.10:devel/rubygem-opentelemetry-instrumentation-active_record \
		rubygem-opentelemetry-instrumentation-active_storage>=0.1.0<0.2:devel/rubygem-opentelemetry-instrumentation-active_storage \
		rubygem-opentelemetry-instrumentation-active_support>=0.8.0<0.9:devel/rubygem-opentelemetry-instrumentation-active_support \
		rubygem-opentelemetry-instrumentation-base>=0.23.0<0.24:devel/rubygem-opentelemetry-instrumentation-base \
		rubygem-opentelemetry-instrumentation-concurrent_ruby>=0.22.0<0.23:devel/rubygem-opentelemetry-instrumentation-concurrent_ruby

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
