# ex:ts=8
# Ports collection makefile for:	jgraph
# Date created:			Jul 9, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jgraph
PORTVERSION=	5.0
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-java1.4-gpl-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Java Graph Diagram Component

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_RUN=	yes

.if !defined(WITHOUT_COMPILE) || !defined(NOPORTDOCS)
BUILD_DEPENDS+=	${ANT_CMD}:${PORTSDIR}/devel/apache-ant
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}
.endif

.if !defined(WITHOUT_COMPILE)
JAVA_BUILD=	yes
ANT_TARGETS=	jar
.endif

.if !defined(NOPORTDOCS)
ANT_TARGETS+=	doc
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

do-build:
.if !defined(WITHOUT_COMPILE) || !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGETS}
	@${MV} -f ${WRKSRC}/build/lib/${PORTNAME}.jar ${WRKSRC}/lib
	@${RM} -fr ${WRKSRC}/doc && ${MV} -f ${WRKSRC}/build/doc/api ${WRKSRC}/doc
.endif

do-install: do-install-jar do-install-javadoc

do-install-jar:
	@${ECHO_CMD} -n  ">> Installing .jar file..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_CMD} " [DONE]"

do-install-javadoc:
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_CMD} " [DONE]"
.endif

.include <bsd.port.mk>
