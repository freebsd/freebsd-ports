PORTNAME=	opentelemetry-instrumentation-base
PORTVERSION=	0.25.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Instrumentation Base for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/base \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api-gitlab>=1.h<2:devel/rubygem-opentelemetry-api-gitlab \
		rubygem-opentelemetry-common-gitlab>=0.21<1:devel/rubygem-opentelemetry-common-gitlab \
		rubygem-opentelemetry-registry-gitlab>=0.1<1:devel/rubygem-opentelemetry-registry-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
