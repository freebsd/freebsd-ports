PORTNAME=	opentelemetry-instrumentation-active_support
PORTVERSION=	0.10.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActiveSupport instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/active_support \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-base-gitlab>=0.25.0<0.26:devel/rubygem-opentelemetry-instrumentation-base-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
