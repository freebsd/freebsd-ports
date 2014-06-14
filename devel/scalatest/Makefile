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

RUN_DEPENDS=	scala>=2.9.0:${PORTSDIR}/lang/scala

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE NOTICE README.txt doc
.endif

SCALA_HOME=	share/scala

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SCALA_HOME}/lib
	${INSTALL_DATA} ${INSTALL_WRKSRC}/scalatest-${PORTVERSION}.jar ${STAGEDIR}${PREFIX}/${SCALA_HOME}/lib/scalatest.jar
	${INSTALL_DATA} ${INSTALL_WRKSRC}/scalatest-${PORTVERSION}-tests.jar ${STAGEDIR}${PREFIX}/${SCALA_HOME}/lib/scalatest-tests.jar
	cd ${INSTALL_WRKSRC}/src/examples \
	  && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/\{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${EXAMPLESDIR}/\{} \;
.if !defined(NOPORTDOCS)
	cd ${INSTALL_WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/\{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${STAGEDIR}${DOCSDIR}/\{} \;
.endif

.include <bsd.port.post.mk>
