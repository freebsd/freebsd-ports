PORTNAME=	opentelemetry
PORTVERSION=	1.3.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMESUFFIX=	-proto

MAINTAINER=	osa@FreeBSD.org
COMMENT=	OpenTelemetry protocol (OTLP) specification and Protobuf definitions
WWW=		https://github.com/open-telemetry/opentelemetry-proto

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	open-telemetry
GH_PROJECT=	opentelemetry-proto

NO_BUILD=	yes

do-install:
	${RM} ${WRKSRC}/opentelemetry/proto/collector/README.md
	${RM} ${WRKSRC}/opentelemetry/proto/collector/*/v1*/*.yaml
	${MKDIR} ${STAGEDIR}${PREFIX}/include/opentelemetry/proto
	(cd ${WRKSRC}/opentelemetry/proto && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/opentelemetry/proto)

.include <bsd.port.mk>
