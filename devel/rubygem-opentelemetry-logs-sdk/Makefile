PORTNAME=	opentelemetry-logs-sdk
PORTVERSION=	0.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Logs SDK implementation for OpenTelemetry
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/logs_sdk \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.2<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-logs-api>=0.1<1:devel/rubygem-opentelemetry-logs-api \
		rubygem-opentelemetry-sdk>=1.3<2:devel/rubygem-opentelemetry-sdk

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
