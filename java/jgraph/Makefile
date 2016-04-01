# Created by: ijliao
# $FreeBSD$

PORTNAME=	jgraph
PORTVERSION=	5.13.0.4
CATEGORIES=	java graphics
MASTER_SITES=	http://www.jgraph.com/downloads/jgraph/archive/ \
		http://www.bayofrum.net/dist/jgraph/
PKGNAMESUFFIX=	-java
EXTRACT_SUFX=	.jar

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Java Graph Diagram Component

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	COMPILE DOCS

COMPILE_DESC=	Compile from source instead of using prebuilt binaries

USES=		zip
NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPILE} || ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${ANT_CMD}:devel/apache-ant
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}
JAVA_BUILD=	yes
ANT_TARGETS=	jar
.  if ${PORT_OPTIONS:MDOCS}
ANT_TARGETS+=	doc
PORTDOCS=	*
.  endif
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-build:
.if ${PORT_OPTIONS:MCOMPILE} || ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGETS}
	@${MV} -f ${WRKSRC}/build/lib/${PORTNAME}.jar ${WRKSRC}/lib
	@${RM} -fr ${WRKSRC}/doc && \
		${MV} -f ${WRKSRC}/build/doc/api ${WRKSRC}/doc
.endif

do-install: do-install-jar do-install-javadoc

do-install-jar:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-javadoc:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
