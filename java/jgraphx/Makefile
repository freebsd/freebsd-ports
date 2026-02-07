PORTNAME=	jgraphx
PORTVERSION=	4.2.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	java graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Graph Diagram Component version X
WWW=		https://github.com/jgraph/jgraphx

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		java:ant,run
USE_GITHUB=	yes
GH_ACCOUNT=	jgraph
JAVA_VERSION=  8 # math/scilab needs java 8 compatible classes

NO_ARCH=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
