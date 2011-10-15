# New ports collection makefile for:	scalatest
# Date created:		Nov 16 2010
# Whom:			Mitsuru YOSHIDA
#
# $FreeBSD$
#

PORTNAME=	scalatest
PORTVERSION=	1.6.1
CATEGORIES=	devel java
MASTER_SITES=	http://www.artima.com/downloadScalaTest/ \
		http://www.scalatest.org/releases/

MAINTAINER=	mitsururike@gmail.com
COMMENT=	A regression testing utility for use with the Scala Language

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	scala>=2.9.0:${PORTSDIR}/lang/scala

USE_ZIP=	yes
USE_JAVA=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE NOTICE README.txt doc
.endif

SCALA_HOME=	share/scala
PLIST_FILES=	${SCALA_HOME}/lib/scalatest.jar \
		${SCALA_HOME}/lib/scalatest-tests.jar
PLIST_DIRSTRY=	${SCALA_HOME}/lib \
		${SCALA_HOME}

do-install:
	${MKDIR} ${PREFIX}/${SCALA_HOME}/lib
	${INSTALL_DATA} ${INSTALL_WRKSRC}/scalatest-${PORTVERSION}.jar ${PREFIX}/${SCALA_HOME}/lib/scalatest.jar
	${INSTALL_DATA} ${INSTALL_WRKSRC}/scalatest-${PORTVERSION}-tests.jar ${PREFIX}/${SCALA_HOME}/lib/scalatest-tests.jar
	cd ${INSTALL_WRKSRC}/src/examples \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
.if !defined(NOPORTDOCS)
	cd ${INSTALL_WRKSRC} \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

post-install:
	@cd ${INSTALL_WRKSRC}/src/examples \
	  && ${FIND} -s . -type f \
	    | ${SED} 's,^\.,${EXAMPLESDIR:S,^${PREFIX}/,,},' >>${TMPPLIST} \
	  && ${FIND} -s -d . -type d \
	    | ${SED} 's,^\.,@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,},' >>${TMPPLIST}

.include <bsd.port.post.mk>
