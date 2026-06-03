PORTNAME=	opentelemetry-semantic_conventions
PORTVERSION=	1.36.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Semantic Convention definitions for OpenTelemetry
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/semantic_conventions \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api-gitlab>=1.0<2:devel/rubygem-opentelemetry-api-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
