PORTNAME=	opentelemetry-exporter-otlp-common
PORTVERSION=	0.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common functionality for the OTLP exporters
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/exporter/otlp-common \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-protobuf>=3.18:devel/rubygem-google-protobuf \
		rubygem-googleapis-common-protos-types>=1.3<2:devel/rubygem-googleapis-common-protos-types \
		rubygem-opentelemetry-api>=1.1<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-common>=0.20<1:devel/rubygem-opentelemetry-common

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
