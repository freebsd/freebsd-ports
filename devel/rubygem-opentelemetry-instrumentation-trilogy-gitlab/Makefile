PORTNAME=	opentelemetry-instrumentation-trilogy
PORTVERSION=	0.65.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Trilogy instrumentation for the OpenTelemetry framework
WWW=		https://opentelemetry.io/ \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib/tree/main/instrumentation/trilogy \
		https://github.com/open-telemetry/opentelemetry-ruby-contrib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-opentelemetry-helpers-mysql-gitlab>=0:devel/rubygem-opentelemetry-helpers-mysql-gitlab \
		rubygem-opentelemetry-helpers-sql-gitlab>=0:devel/rubygem-opentelemetry-helpers-sql-gitlab \
		rubygem-opentelemetry-helpers-sql-processor-gitlab>=0:devel/rubygem-opentelemetry-helpers-sql-processor-gitlab \
		rubygem-opentelemetry-instrumentation-base-gitlab>=0.25<1:devel/rubygem-opentelemetry-instrumentation-base-gitlab \
		rubygem-opentelemetry-semantic_conventions-gitlab>=1.8.0:devel/rubygem-opentelemetry-semantic_conventions-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
