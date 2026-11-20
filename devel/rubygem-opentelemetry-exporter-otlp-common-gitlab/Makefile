PORTNAME=	opentelemetry-exporter-otlp-common
PORTVERSION=	0.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Common functionality for the OTLP exporters
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/exporter/otlp-common \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-protobuf-gitlab>=3.18:devel/rubygem-google-protobuf-gitlab \
		rubygem-googleapis-common-protos-types-gitlab>=1.3<2:devel/rubygem-googleapis-common-protos-types-gitlab \
		rubygem-opentelemetry-api-gitlab>=1.1<2:devel/rubygem-opentelemetry-api-gitlab \
		rubygem-opentelemetry-common-gitlab>=0.20<1:devel/rubygem-opentelemetry-common-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
