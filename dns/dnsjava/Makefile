# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnsjava
PORTVERSION=	2.1.6
CATEGORIES=	dns java
MASTER_SITES=	http://www.dnsjava.org/download/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Implementation of DNS in Java

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	jar docs

OPTIONS_DEFINE=	DOCS EXAMPLES

SAMPLE_FILES=	examples.html USAGE dig.java jnamed.java lookup.java update.java
OTHERDOCS=	README Changelog

do-build:
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${ANT} ${ALL_TARGET})

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${SAMPLE_FILES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc -cf - . | ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -
	${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
