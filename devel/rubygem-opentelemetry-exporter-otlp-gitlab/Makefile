PORTNAME=	opentelemetry-exporter-otlp
PORTVERSION=	0.31.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	OTLP exporter for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/exporter/otlp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-googleapis-common-protos-types-gitlab>=1.3<2:devel/rubygem-googleapis-common-protos-types-gitlab \
		rubygem-google-protobuf>=3.18:devel/rubygem-google-protobuf \
		rubygem-opentelemetry-api-gitlab>=1.1<2:devel/rubygem-opentelemetry-api-gitlab \
		rubygem-opentelemetry-common-gitlab>=0.20<1:devel/rubygem-opentelemetry-common-gitlab \
		rubygem-opentelemetry-sdk-gitlab>=1.10<2:devel/rubygem-opentelemetry-sdk-gitlab \
		rubygem-opentelemetry-semantic_conventions-gitlab>=0:devel/rubygem-opentelemetry-semantic_conventions-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
