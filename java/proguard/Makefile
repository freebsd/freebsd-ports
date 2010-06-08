# New ports collection makefile for:	proguard
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	proguard
PORTVERSION=	4.5
CATEGORIES=	java devel
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java class file shrinker, optimizer, and obfuscator

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

LICENSE=	GPLv2

USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	proguard.sh proguard-gui.sh retrace.sh

PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/proguard.sh ${PREFIX}/bin/proguard
	${INSTALL_SCRIPT} ${WRKDIR}/proguard-gui.sh ${PREFIX}/bin/proguard-gui
	${INSTALL_SCRIPT} ${WRKDIR}/retrace.sh ${PREFIX}/bin/retrace
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}/)
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
