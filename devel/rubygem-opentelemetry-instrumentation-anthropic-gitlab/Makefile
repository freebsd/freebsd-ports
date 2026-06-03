PORTNAME=	opentelemetry-instrumentation-anthropic
PORTVERSION=	0.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Anthropic instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/anthropic \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-base-gitlab>=0.25<1:devel/rubygem-opentelemetry-instrumentation-base-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
