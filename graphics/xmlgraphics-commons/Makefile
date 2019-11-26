# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	xmlgraphics-commons
PORTVERSION=	2.4
DISTVERSIONSUFFIX=	-bin
CATEGORIES=	graphics textproc java
MASTER_SITES=	APACHE/xmlgraphics/commons/binaries

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Several reusable components used by Apache Batik and FOP

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_JAVA=	yes

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	${JAVAJARDIR}/${JARFILE_VER} \
		${JAVAJARDIR}/${JARFILE}
PORTDOCS=	*

JARFILE=	${PORTNAME}.jar
JARFILE_VER=	${PORTNAME}-${PORTVERSION}.jar

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/${JARFILE_VER} ${STAGEDIR}${JAVAJARDIR}
	${LN} -sf ${JARFILE_VER} ${STAGEDIR}${JAVAJARDIR}/${JARFILE}

do-install-DOCS-on:
	(cd ${WRKSRC}/javadocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} \
		NOTICE README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
