# Created by: FreeBSD Bio porters (bio@freebsd.net)
# $FreeBSD$

PORTNAME=	biojava
DISTVERSION=	1.7
PORTEPOCH=	1
CATEGORIES=	biology java
MASTER_SITES=	http://www.biojava.org/download/bj17/all/
DISTNAME=	${PORTNAME}-${DISTVERSION}-all
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source Java tools for processing biological data

BROKEN=		Does not build

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
MAKE_ENV=	CLASSPATH="${JAVALIBDIR}"
ALL_TARGET=	package-biojava

JARFILES=	biojava.jar bytecode.jar
PORTDOCS=	biojava
PORTEXAMPLES=	demos
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if !defined(WITHOUT_TESTS)
regression-test:
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} runtests)
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@${INSTALL_DATA} ${JARFILES:S|^|${WRKSRC}/ant-build/|} ${STAGEDIR}${JAVAJARDIR}
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} biojava ${STAGEDIR}${DOCSDIR})
	@${ECHO_MSG} " [ DONE ]"

	@${ECHO_MSG} -n ">> Installing examples in ${EXAMPLESDIR}..."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} demos ${STAGEDIR}${EXAMPLESDIR})
	@${ECHO_MSG} " [ DONE ]"

.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Libraries installed at: ${JAVAJARDIR}"
	@${ECHO_MSG} "You should edit your CLASSPATH to include the jar files"
	@${ECHO_MSG} "in this directory."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Docs and demos are installed in:"
	@${ECHO_MSG} "${DOCSDIR}"
	@${ECHO_MSG} ""
.endif

.include <bsd.port.mk>
