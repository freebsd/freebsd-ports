PORTNAME=	opentelemetry-exporter-otlp
PORTVERSION=	0.26.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OTLP exporter for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/exporter/otlp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-googleapis-common-protos-types>=1.3<2:devel/rubygem-googleapis-common-protos-types \
		rubygem-google-protobuf>=3.14<4:devel/rubygem-google-protobuf \
		rubygem-opentelemetry-api>=1.1<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-common>=0.20<1:devel/rubygem-opentelemetry-common \
		rubygem-opentelemetry-sdk>=1.2<2:devel/rubygem-opentelemetry-sdk \
		rubygem-opentelemetry-instrumentation-base>=0.22.1<0.23:devel/rubygem-opentelemetry-instrumentation-base \
		rubygem-opentelemetry-semantic_conventions>=0:devel/rubygem-opentelemetry-semantic_conventions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
