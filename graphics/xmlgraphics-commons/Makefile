PORTNAME=	xmlgraphics-commons
DISTVERSION=	2.11
DISTVERSIONSUFFIX=	-bin
CATEGORIES=	graphics textproc java
MASTER_SITES=	APACHE/xmlgraphics/commons/binaries \
		https://archive.apache.org/dist/xmlgraphics/commons/binaries/

MAINTAINER=	atanubiswas484@gmail.com
COMMENT=	Several reusable components used by Apache Batik and FOP
WWW=		https://xmlgraphics.apache.org/commons/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		java

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	${JAVAJARDIR}/${JARFILE_VER} \
		${JAVAJARDIR}/${JARFILE}
PORTDOCS=	*

JARFILE=	${PORTNAME}.jar
JARFILE_VER=	${PORTNAME}-${DISTVERSION}.jar

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/${JARFILE_VER} ${STAGEDIR}${JAVAJARDIR}
	${LN} -sf ${JARFILE_VER} ${STAGEDIR}${JAVAJARDIR}/${JARFILE}

do-install-DOCS-on:
	(cd ${WRKSRC}/javadocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} \
		NOTICE README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
