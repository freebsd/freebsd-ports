PORTNAME=	opentelemetry-instrumentation-action_mailer
PORTVERSION=	0.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActionMailer instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/action_mailer \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.0<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-instrumentation-active_support>=0.7<1:devel/rubygem-opentelemetry-instrumentation-active_support \
		rubygem-opentelemetry-instrumentation-base>=0.23.0<0.24:devel/rubygem-opentelemetry-instrumentation-base

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
