PORTNAME=	opentelemetry-instrumentation-grape
PORTVERSION=	0.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Grape instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/grape

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-instrumentation-rack>=0.29<1:devel/rubygem-opentelemetry-instrumentation-rack

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
