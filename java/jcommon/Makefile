# ex:ts=8
# Ports collection makefile for:	jcommon
# Date created:			Nov 11, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jcommon
PORTVERSION=	0.9.5
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	jfreechart

MAINTAINER=	sepherosa@softhome.net
COMMENT=	A collection of useful classes used by JFreeChart and JFreeReport

USE_JAVA=	yes
JAVA_VERSION=	1.2+

.if !defined(WITHOUT_COMPILE) || !defined(NOPORTDOCS)
BUILD_DEPENDS=	${ANT_CMD}:${PORTSDIR}/devel/apache-ant
ANT_CMD?=	${LOCALBASE}/bin/ant
ANT=		${SETENV} JAVA_HOME=${JAVA_HOME} ${ANT_CMD}
.endif

.if !defined(WITHOUT_COMPILE)
JAVA_BUILD=	yes
ANT_TARGETS=	compile
.else
JAVA_RUN=	yes
.endif

.if !defined(NOPORTDOCS)
ANT_TARGETS+=	javadoc
PORTDOCS=	*
.endif

PLIST_SUB+=	JAVAJARDIR=${JAVAJARDIR:S|^${PREFIX}/||}
PLIST_FILES=	%%JAVAJARDIR%%/jcommon.jar

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "    WITHOUT_COMPILE=yes    Install the pre-compiled .jar file"
	@${ECHO_MSG} ""

do-build:
.if !defined(WITHOUT_COMPILE) || !defined(NOPORTDOCS)
	@cd ${WRKSRC}/ant && ${ANT} ${ANT_TARGETS}
.endif

do-install: do-install-jar do-install-javadoc

do-install-jar:
	@${ECHO_CMD} -n  ">> Installing .jar file..."
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_CMD} " [DONE]"

do-install-javadoc:
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/javadoc && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_CMD} " [DONE]"
.endif

.include <bsd.port.mk>
