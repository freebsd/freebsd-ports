PORTNAME=	opentelemetry-helpers-mysql
PORTVERSION=	0.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MySQL Instrumentation Helpers for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/helpers/mysql \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.7<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-common>=0.21<1:devel/rubygem-opentelemetry-common

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
