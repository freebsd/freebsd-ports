PORTNAME=	opentelemetry-instrumentation-pg
PORTVERSION=	0.31.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	PG (PostgreSQL) instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/pg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-helpers-sql>=0:devel/rubygem-opentelemetry-helpers-sql \
		rubygem-opentelemetry-helpers-sql-obfuscation>=0:devel/rubygem-opentelemetry-helpers-sql-obfuscation \
		rubygem-opentelemetry-instrumentation-base>=0.23<1:devel/rubygem-opentelemetry-instrumentation-base

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
