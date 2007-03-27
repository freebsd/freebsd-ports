# New ports collection makefile for: biojava
# Date created:	15 September 2000
# Whom:		FreeBSD Bio porters (bio@freebsd.net)
#
# $FreeBSD$
#

PORTNAME=	biojava
DISTVERSION=	1.5-beta2
PORTEPOCH=	1
CATEGORIES=	biology java
MASTER_SITES=	http://www.biojava.org/download/bj15b/all/:source	\
		http://www.biojava.org/download/bj15b/bin/:bin
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}:source	\
		bytecode.jar:bin
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemoliu@gmail.com
COMMENT=	Open-source java tools for processing biological data

BUILD_DEPENDS=	${JAVALIBDIR}/hsqldb.jar:${PORTSDIR}/databases/hsqldb \
		${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j \
		${JAVALIBDIR}/jakarta-regexp.jar:${PORTSDIR}/java/jakarta-regexp \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/commons-dbcp.jar:${PORTSDIR}/java/jakarta-commons-dbcp \
		${JAVALIBDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool \
		${JAVALIBDIR}/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections
RUN_DEPENDS=	${JAVALIBDIR}/hsqldb.jar:${PORTSDIR}/databases/hsqldb \
		${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j \
		${JAVALIBDIR}/jakarta-regexp.jar:${PORTSDIR}/java/jakarta-regexp \
		${JAVALIBDIR}/commons-cli.jar:${PORTSDIR}/java/jakarta-commons-cli \
		${JAVALIBDIR}/commons-dbcp.jar:${PORTSDIR}/java/jakarta-commons-dbcp \
		${JAVALIBDIR}/commons-pool.jar:${PORTSDIR}/java/jakarta-commons-pool \
		${JAVALIBDIR}/commons-collections.jar:${PORTSDIR}/java/jakarta-commons-collections

.if !defined(WITHOUT_TESTS)
BUILD_DEPENDS+=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes
MAKE_ENV=	CLASSPATH="${JAVALIBDIR}"
ALL_TARGET=	compile-apps

PLIST_SUB+=	VER=${DISTVERSION}

JARFILES=	apps-${DISTVERSION}.jar biojava.jar bytecode.jar
PORTDOCS=	biojava
SAMPLES=	demos
WRKSRC=${WRKDIR}

.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadocs-biojava
.endif
.if !defined(WITHOUT_SAMPLES)
ALL_TARGET+=	compile-demos
PLIST_SUB+=	INSTEX=""
.else
PLIST_SUB+=	INSTEX="@comment "
.endif

post-extract:
	${CP} ${_DISTDIR}/bytecode.jar ${WRKSRC}

.if !defined(WITHOUT_TESTS)
regression-test:
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} runtests)
.endif

# from textproc/xerces-j
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
	@cd ${WRKSRC}/ant-build/docs && \
		${FIND} ${PORTDOCS} -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} ${PORTDOCS} -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	@${ECHO_MSG} " [ DONE ]"
.endif
.if !defined(WITHOUT_SAMPLES)
	@${ECHO_MSG} -n ">> Installing demos in ${EXAMPLESDIR}..."
	cd ${WRKSRC} && \
		${FIND} ${SAMPLES} -type d -exec ${MKDIR} "${EXAMPLESDIR}/{}" \; && \
		${FIND} ${SAMPLES} -not -type d -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
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
