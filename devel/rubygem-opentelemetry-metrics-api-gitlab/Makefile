PORTNAME=	opentelemetry-metrics-api
PORTVERSION=	0.10.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Stats collection and distributed tracing framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/metrics_api \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api-gitlab>=1.0<2:devel/rubygem-opentelemetry-api-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
