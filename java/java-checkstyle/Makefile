# Ports collection makefile for:    Java Checkstyle
# Date created:         2002/09/02
# Whom:                 Dave Glowacki <dglo@ssec.wisc.edu>
#
# $FreeBSD$
#

PORTNAME=	checkstyle
PORTVERSION=	5.3
CATEGORIES=	java devel
MASTER_SITES=	SF
PKGNAMEPREFIX=	java-
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java style checker

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

JAR_FILE=	${PORTNAME}-${PORTVERSION}-all.jar

PLIST_FILES=	bin/${PORTNAME} \
		%%JAVAJARDIR%%/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

SUB_FILES=	${PORTNAME}.sh

do-install:
	@-${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/${JAR_FILE} ${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@-${MKDIR} ${DOCSDIR}
.for DOCFILE in LICENSE* README RIGHTS.antlr
	@${INSTALL_DATA} ${WRKSRC}/${DOCFILE} ${DOCSDIR}/
.endfor
	@cd ${WRKSRC} && ${COPYTREE_SHARE} site ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@-${MKDIR} ${EXAMPLESDIR}
.for EXAMPLEFILE in checkstyle_checks import-control sun_checks suppressions
	@${INSTALL_DATA} ${WRKSRC}/${EXAMPLEFILE}.xml ${EXAMPLESDIR}/
.endfor
	@cd ${WRKSRC} && ${COPYTREE_SHARE} contrib ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
