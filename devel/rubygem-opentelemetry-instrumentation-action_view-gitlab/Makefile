PORTNAME=	opentelemetry-instrumentation-action_view
PORTVERSION=	0.11.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActionView instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/action_view \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-active_support-gitlab>=0.10<1:devel/rubygem-opentelemetry-instrumentation-active_support-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
