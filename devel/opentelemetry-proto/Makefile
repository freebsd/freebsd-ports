PORTNAME=	opentelemetry
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
CATEGORIES=	devel
PKGNAMESUFFIX=	-proto

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	OpenTelemetry protocol (OTLP) specification and Protobuf definitions
WWW=		https://github.com/open-telemetry/opentelemetry-proto

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	open-telemetry
GH_PROJECT=	opentelemetry-proto

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${RM}   ${WRKSRC}/opentelemetry/proto/collector/README.md \
		${WRKSRC}/opentelemetry/proto/collector/*/v1*/*.yaml
	${MKDIR} ${STAGEDIR}${PREFIX}/include/opentelemetry/proto
	(cd ${WRKSRC}/opentelemetry/proto && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/opentelemetry/proto)

.include <bsd.port.mk>
