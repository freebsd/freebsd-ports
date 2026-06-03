PORTNAME=	opentelemetry-common
PORTVERSION=	0.23.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Common helpers for OpenTelemetry
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby/tree/main/common \
		https://github.com/open-telemetry/opentelemetry-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-api-gitlab>=1.0<2:devel/rubygem-opentelemetry-api-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
