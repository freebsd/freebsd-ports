# New ports collection makefile for: biojava
# Date created:	15 September 2000
# Whom:		FreeBSD Bio porters (bio@freebsd.net)
#
# $FreeBSD$
#

PORTNAME=	biojava
DISTVERSION=	1.7
PORTEPOCH=	1
CATEGORIES=	biology java
MASTER_SITES=	http://www.biojava.org/download/bj17/all/
DISTNAME=	${PORTNAME}-${DISTVERSION}-all
EXTRACT_SUFX=	.jar

MAINTAINER=	wenheping@gmail.com
COMMENT=	Open-source Java tools for processing biological data

EXTRACT_DEPENDS+=	jar:${PORTSDIR}/java/diablo-jdk16

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes
MAKE_ENV=	CLASSPATH="${JAVALIBDIR}"
ALL_TARGET=	package-biojava

JARFILES=	biojava.jar bytecode.jar
PORTDOCS=	biojava
PORTEXAMPLES=	demos
EXTRACT_CMD=	jar -xvf ${_DISTDIR}/${DISTFILES}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${EXTRACT_CMD}

.if !defined(WITHOUT_TESTS)
regression-test:
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} runtests)
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
.for JARFILE in ${JARFILES}
	@cd ${WRKSRC}/ant-build && ${INSTALL_DATA} ${JARFILE} ${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} -n " ${JARFILE}"
.endfor
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} ${PORTDOCS} -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} ${PORTDOCS} -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} -n ">> Installing examples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/doc && \
		${FIND} ${PORTEXAMPLES} -type d -exec ${MKDIR} "${EXAMPLESDIR}/{}" \; && \
		${FIND} ${PORTEXAMPLES} -not -type d -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
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
