# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jdom
PORTVERSION=	1.1.1
PORTEPOCH=	1
CATEGORIES=	java textproc
MASTER_SITES=	http://www.jdom.org/dist/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java library for accessing and manipulating XML documents

RUN_DEPENDS=	${JAVALIBDIR}/jaxen-jdom.jar:java/jaxen

USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	package

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	CLASSPATH=${JAVALIBDIR}/jaxen-jdom.jar

PLIST_FILES=	%%JAVAJARDIR%%/jdom.jar
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/jdom.jar ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/build/samples/ && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build && ${COPYTREE_SHARE} apidocs ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} README.txt TODO.txt CHANGES.txt \
		COMMITTERS.txt LICENSE.txt ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
