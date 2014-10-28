# Created by: Alex Semenyaka <alex@rinet.ru>
# $FreeBSD$

PORTNAME=	proguard
PORTVERSION=	5.1
CATEGORIES=	java devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java class file shrinker, optimizer, and obfuscator

LICENSE=	GPLv2

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	proguard.sh proguard-gui.sh retrace.sh

PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/proguard.sh ${STAGEDIR}${PREFIX}/bin/proguard
	${INSTALL_SCRIPT} ${WRKDIR}/proguard-gui.sh ${STAGEDIR}${PREFIX}/bin/proguard-gui
	${INSTALL_SCRIPT} ${WRKDIR}/retrace.sh ${STAGEDIR}${PREFIX}/bin/retrace
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
