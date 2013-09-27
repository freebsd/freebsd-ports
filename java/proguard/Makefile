# Created by: Alex Semenyaka <alex@rinet.ru>
# $FreeBSD$

PORTNAME=	proguard
PORTVERSION=	4.10
CATEGORIES=	java devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION:S/.1$//}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java class file shrinker, optimizer, and obfuscator

LICENSE=	GPLv2

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	proguard.sh proguard-gui.sh retrace.sh

PORTDOCS=	*
PORTEXAMPLES=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/proguard.sh ${PREFIX}/bin/proguard
	${INSTALL_SCRIPT} ${WRKDIR}/proguard-gui.sh ${PREFIX}/bin/proguard-gui
	${INSTALL_SCRIPT} ${WRKDIR}/retrace.sh ${PREFIX}/bin/retrace
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}/)
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
