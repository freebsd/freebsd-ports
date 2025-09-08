PORTNAME=	opentelemetry-sdk
PORTVERSION=	1.8.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stats collection and distributed tracing framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/sdk

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api>=1.1<2:devel/rubygem-opentelemetry-api \
		rubygem-opentelemetry-common>=0.20<1:devel/rubygem-opentelemetry-common \
		rubygem-opentelemetry-registry>=0.2<1:devel/rubygem-opentelemetry-registry \
		rubygem-opentelemetry-semantic_conventions>=0:devel/rubygem-opentelemetry-semantic_conventions

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
