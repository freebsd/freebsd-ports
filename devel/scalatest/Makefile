# Created by: Mitsuru YOSHIDA
# $FreeBSD$

PORTNAME=	scalatest
PORTVERSION=	1.6.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.artima.com/downloadScalaTest/ \
		http://www.scalatest.org/releases/

MAINTAINER=	mitsururike@gmail.com
COMMENT=	Regression testing utility for use with the Scala Language

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	scala>=2.9.0:lang/scala

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes

PORTDOCS=	LICENSE NOTICE README.txt doc

SCALA_HOME=	share/scala

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SCALA_HOME}/lib
	${INSTALL_DATA} ${INSTALL_WRKSRC}/scalatest-${PORTVERSION}.jar ${STAGEDIR}${PREFIX}/${SCALA_HOME}/lib/scalatest.jar
	${INSTALL_DATA} ${INSTALL_WRKSRC}/scalatest-${PORTVERSION}-tests.jar ${STAGEDIR}${PREFIX}/${SCALA_HOME}/lib/scalatest-tests.jar
	cd ${INSTALL_WRKSRC}/src/examples \
	  && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/\{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${EXAMPLESDIR}/\{} \;
	cd ${INSTALL_WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${DOCSDIR}/\{} \;

.include <bsd.port.mk>
