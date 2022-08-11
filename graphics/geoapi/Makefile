PORTNAME=	geoapi
PORTVERSION=	3.0.0
CATEGORIES=	graphics geography
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	GeoAPI-3_0_0

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Java interface API based upon OGC Standards

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
NO_WRKSUBDIR=	yes

JARFILES=	geoapi-${PORTVERSION} jsr-275-0.9.3 geoapi-conformance-${PORTVERSION}
DOCS=		README.txt

OPTIONS_DEFINE=	DOCS

do-install:
.for jar in ${JARFILES}
	${INSTALL_DATA} ${WRKSRC}/${jar}.jar ${STAGEDIR}${JAVAJARDIR}
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/javadoc \
		&& ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${DOCSDIR}/\{} \;

.include <bsd.port.mk>
