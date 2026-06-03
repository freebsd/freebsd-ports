PORTNAME=	opentelemetry-registry
PORTVERSION=	0.4.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Registry for the OpenTelemetry Instrumentation libraries
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/registry \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api-gitlab>=1.1<2:devel/rubygem-opentelemetry-api-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
