PORTNAME=	opentelemetry-instrumentation-rails
PORTVERSION=	0.42.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Rails instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/rails \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	Apache-2.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-action_mailer-gitlab>=0.7<1:devel/rubygem-opentelemetry-instrumentation-action_mailer-gitlab \
		rubygem-opentelemetry-instrumentation-action_pack-gitlab>=0.17<1:devel/rubygem-opentelemetry-instrumentation-action_pack-gitlab \
		rubygem-opentelemetry-instrumentation-action_view-gitlab>=0.12<1:devel/rubygem-opentelemetry-instrumentation-action_view-gitlab \
		rubygem-opentelemetry-instrumentation-active_job-gitlab>=0.11<1:devel/rubygem-opentelemetry-instrumentation-active_job-gitlab \
		rubygem-opentelemetry-instrumentation-active_record-gitlab>=0.12<1:devel/rubygem-opentelemetry-instrumentation-active_record-gitlab \
		rubygem-opentelemetry-instrumentation-active_storage-gitlab>=0.4<1:devel/rubygem-opentelemetry-instrumentation-active_storage-gitlab \
		rubygem-opentelemetry-instrumentation-active_support-gitlab>=0.11<1:devel/rubygem-opentelemetry-instrumentation-active_support-gitlab \
		rubygem-opentelemetry-instrumentation-concurrent_ruby-gitlab>=0.25<1:devel/rubygem-opentelemetry-instrumentation-concurrent_ruby-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
