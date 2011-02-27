# New ports collection makefile for:	thistest
# Date created:				2007-12-24
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	thistest
PORTVERSION=	1.3
CATEGORIES=	devel java
MASTER_SITES=	#
DISTNAME=	thisTest
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Java unit testing framework

DEPRECATED=	development has ceased; website disappeared
EXPIRATION_DATE=	2011-04-11

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_ANT=	yes
NO_WRKSUBDIR=	yes
RESTRICTED=	Redistribution of pre-compiled binaries is not permitted

JARFILE=	${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		needs you to download ${DISTNAME}${EXTRACT_SUFX} manually from "http://www.flosoft-systems.com" and place it under ${DISTDIR}
.endif

post-build:
	@(${ECHO_CMD} '#!${SH}'; \
	  ${ECHO_CMD} 'exec ${JAVA} -jar ${JAVAJARDIR}/${JARFILE} "$$@"') \
	  > ${WRKSRC}/${PORTNAME}

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && jar fx ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
	@${CP} ${FILESDIR}/build.xml ${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
