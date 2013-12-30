# $FreeBSD$

PORTNAME=	jgraphx
PORTVERSION=	1.10.3.0
CATEGORIES=	java graphics
MASTER_SITES=	GH

MAINTAINER=	crees@FreeBSD.org
COMMENT=	The Java Graph Diagram Component version X (jgraph v6+)

LICENSE=	jgraph
LICENSE_PERMS=	# none
LICENSE_NAME=	JGraph Ltd License
LICENSE_FILE=	${WRKSRC}/license.txt
MANUAL_PACKAGE_BUILD=	needs interactive license confirmation

USE_GITHUB=	yes
GH_ACCOUNT=	jgraph
GH_COMMIT=	b445bde

OPTIONS_DEFINE=	COMPILE DOCS

COMPILE_DESC=	Compile from source instead of using provided binary

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_RUN=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPILE} || ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	${ANT_CMD}:${PORTSDIR}/devel/apache-ant
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}
.  if ${PORT_OPTIONS:MCOMPILE}
JAVA_BUILD=	yes
.  endif
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	*

do-build:
.if ${PORT_OPTIONS:MCOMPILE} || ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC} && ${ANT} ${ANT_TARGETS}
.endif

do-install: do-install-jar do-install-javadoc

do-install-jar:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-javadoc:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
