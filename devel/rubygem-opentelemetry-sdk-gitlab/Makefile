PORTNAME=	opentelemetry-sdk
PORTVERSION=	1.10.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Stats collection and distributed tracing framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/sdk \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api-gitlab>=1.1<2:devel/rubygem-opentelemetry-api-gitlab \
		rubygem-opentelemetry-common-gitlab>=0.20<1:devel/rubygem-opentelemetry-common-gitlab \
		rubygem-opentelemetry-registry-gitlab>=0.2<1:devel/rubygem-opentelemetry-registry-gitlab \
		rubygem-opentelemetry-semantic_conventions-gitlab>=0:devel/rubygem-opentelemetry-semantic_conventions-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
