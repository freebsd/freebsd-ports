PORTNAME=	opentelemetry-instrumentation-sinatra
PORTVERSION=	0.26.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sinatra instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/sinatra \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.0<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-instrumentation-base>=0.23.0<0.24:devel/rubygem-opentelemetry-instrumentation-base \
		rubygem-opentelemetry-instrumentation-rack>=0.21<1:devel/rubygem-opentelemetry-instrumentation-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
