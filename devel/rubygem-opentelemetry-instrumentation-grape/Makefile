PORTNAME=	opentelemetry-instrumentation-grape
PORTVERSION=	0.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Grape instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/grape

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.0<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-instrumentation-base>=0.22.1<0.23:devel/rubygem-opentelemetry-instrumentation-base \
		rubygem-opentelemetry-instrumentation-rack>=0.21<1:devel/rubygem-opentelemetry-instrumentation-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
