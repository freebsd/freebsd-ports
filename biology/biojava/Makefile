# New ports collection makefile for: biojava
# Date created:	15 September 2000
# Whom:		FreeBSD Bio porters (bio@freebsd.net)
#
# $FreeBSD$
#

PORTNAME=	biojava
PORTVERSION=	1.30
CATEGORIES=	biology java
MASTER_SITES=	http://www.biojava.org/download/source/

MAINTAINER=	whitekid@gmail.com
COMMENT=	Open-source java tools for processing biological data

RUN_DEPENDS=	${JAVAJARDIR:S,^${PREFIX},${LOCALBASE},}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j \
		${JAVAJARDIR:S,^${PREFIX},${LOCALBASE},}/jakarta-regexp.jar:${PORTSDIR}/java/jakarta-regexp

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ANT=	yes

JARFILES=	biojava.jar bytecode.jar
PORTDOCS=	api
SAMPLES=	demos demos-1.4 demos-obsolete

post-build:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Build javadocs..."
	@cd ${WRKSRC} && ant javadocs
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
