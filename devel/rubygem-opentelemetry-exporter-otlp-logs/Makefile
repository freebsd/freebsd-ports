PORTNAME=	opentelemetry-exporter-otlp-logs
PORTVERSION=	0.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Experimental OTLP Logs exporter for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/exporter/otlp-logs \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-protobuf>=3.18:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos-types>=1.3<2:devel/rubygem-googleapis-common-protos-types \
		rubygem-opentelemetry-api>=1.1<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-common>=0.20<1:devel/rubygem-opentelemetry-common \
		rubygem-opentelemetry-logs-api>=0.1<1:devel/rubygem-opentelemetry-logs-api \
		rubygem-opentelemetry-logs-sdk>=0.1<1:devel/rubygem-opentelemetry-logs-sdk \
		rubygem-opentelemetry-sdk>=0:devel/rubygem-opentelemetry-sdk \
		rubygem-opentelemetry-semantic_conventions>=0:devel/rubygem-opentelemetry-semantic_conventions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
