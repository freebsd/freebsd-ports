PORTNAME=	opentelemetry-instrumentation-action_pack
PORTVERSION=	0.16.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	ActionPack instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/action_pack \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-rack-gitlab>=0.29<1:devel/rubygem-opentelemetry-instrumentation-rack-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
