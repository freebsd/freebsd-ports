PORTNAME=	opentelemetry-exporter-otlp
PORTVERSION=	0.30.0
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
		rubygem-google-protobuf>=3.18:devel/rubygem-google-protobuf \
		rubygem-opentelemetry-api>=1.1<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-common>=0.20<1:devel/rubygem-opentelemetry-common \
		rubygem-opentelemetry-sdk>=1.2<2:devel/rubygem-opentelemetry-sdk \
		rubygem-opentelemetry-semantic_conventions>=0:devel/rubygem-opentelemetry-semantic_conventions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
