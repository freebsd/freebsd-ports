# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	geoapi
PORTVERSION=	2.1.1
CATEGORIES=	graphics geography
MASTER_SITES=	SF
DISTNAME=	GeoAPI-2_1_1

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Java interface API based upon OGC Standards

USES=		zip
NO_BUILD=	yes
USE_JAVA=	yes
NO_WRKSUBDIR=	yes

JARFILES=	geoapi-${PORTVERSION} jsr108-0.01 geoapi-nogenerics-${PORTVERSION}
DOCS=		README.txt

NO_STAGE=	yes
do-install:
.for jar in ${JARFILES}
	${INSTALL_DATA} ${WRKSRC}/binaries/${jar}.jar ${JAVAJARDIR}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/javadoc \
		&& ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.mk>
