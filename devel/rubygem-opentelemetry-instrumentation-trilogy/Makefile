PORTNAME=	opentelemetry-instrumentation-trilogy
PORTVERSION=	0.59.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Trilogy instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/trilogy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.0<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-helpers-mysql>=0:devel/rubygem-opentelemetry-helpers-mysql \
		rubygem-opentelemetry-helpers-sql-obfuscation>=0:devel/rubygem-opentelemetry-helpers-sql-obfuscation \
		rubygem-opentelemetry-instrumentation-base>=0.22.1<0.23:devel/rubygem-opentelemetry-instrumentation-base \
		rubygem-opentelemetry-semantic_conventions>=1.8.0:devel/rubygem-opentelemetry-semantic_conventions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
