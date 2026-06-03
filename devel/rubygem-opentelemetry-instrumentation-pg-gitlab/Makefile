PORTNAME=	opentelemetry-instrumentation-pg
PORTVERSION=	0.34.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	PG (PostgreSQL) instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/pg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-helpers-sql-gitlab>=0:devel/rubygem-opentelemetry-helpers-sql-gitlab \
		rubygem-opentelemetry-helpers-sql-processor-gitlab>=0:devel/rubygem-opentelemetry-helpers-sql-processor-gitlab \
		rubygem-opentelemetry-instrumentation-base-gitlab>=0.25<1:devel/rubygem-opentelemetry-instrumentation-base-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
