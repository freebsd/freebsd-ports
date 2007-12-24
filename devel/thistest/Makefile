# New ports collection makefile for:	thistest
# Date created:				2007-12-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	thistest
PORTVERSION=	1.2
CATEGORIES=	devel java
MASTER_SITES=	#
DISTNAME=	thisTest
EXTRACT_SUFX=	.jar

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	A Java unit testing framework

USE_JAVA=	yes
JAVA_VERSION=	1.6
NO_WRKSUBDIR=	yes
RESTRICTED=	Redistribution of pre-compiled binaries is not permitted

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		needs you to download ${DISTNAME}${EXTRACT_SUFX} manually from "http://www.flosoft-systems.com" and place it under ${DISTDIR}
.endif

do-build:
	@(${ECHO_CMD} '#!${SH}'; \
	  ${ECHO_CMD} 'exec ${JAVA} -jar ${JAVAJARDIR}/${DISTNAME}${EXTRACT_SUFX} "$$@"') \
	  > ${WRKSRC}/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && jar fx ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
