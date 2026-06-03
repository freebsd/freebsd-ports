PORTNAME=	opentelemetry-instrumentation-faraday
PORTVERSION=	0.30.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Faraday instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/faraday

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-base-gitlab>=0.25<1:devel/rubygem-opentelemetry-instrumentation-base-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
