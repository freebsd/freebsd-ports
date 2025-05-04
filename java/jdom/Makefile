PORTNAME=	jdom
PORTVERSION=	1.1.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	java textproc
MASTER_SITES=	http://www.jdom.org/dist/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java library for accessing and manipulating XML documents
WWW=		http://www.jdom.org/

DEPRECATED=	Depends on exired java/jaxen
EXPIRATION_DATE=2025-06-04

RUN_DEPENDS=	${JAVALIBDIR}/jaxen-jdom.jar:java/jaxen

USES=		java:ant,run
JAVA_VERSION=	8

ALL_TARGET=	package

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	CLASSPATH=${JAVALIBDIR}/jaxen-jdom.jar

PLIST_FILES=	%%JAVAJARDIR%%/jdom.jar
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_ALL_TARGET=	javadoc

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/jdom.jar ${STAGEDIR}${JAVAJARDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} README.txt TODO.txt CHANGES.txt \
		COMMITTERS.txt LICENSE.txt ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/build/samples/ && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
