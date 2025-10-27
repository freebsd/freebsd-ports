PORTNAME=	opentelemetry-metrics-sdk
PORTVERSION=	0.10.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stats collection and distributed tracing framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/metrics_sdk \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.1<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-metrics-api>=0.2<1:devel/rubygem-opentelemetry-metrics-api \
		rubygem-opentelemetry-sdk>=1.2<2:devel/rubygem-opentelemetry-sdk

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
