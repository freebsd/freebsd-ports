PORTNAME=	opentelemetry-instrumentation-openai
PORTVERSION=	0.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenAI instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/openai \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-base>=0.27<1:devel/rubygem-opentelemetry-instrumentation-base

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
