# Created by: Alex Semenyaka <alex@rinet.ru>
# $FreeBSD$

PORTNAME=	proguard
PORTVERSION=	6.0.1
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION:C/.[0-9]$//}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java class file shrinker, optimizer, and obfuscator

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	proguard.sh proguard-gui.sh retrace.sh

PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/lib/*.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/proguard.sh ${STAGEDIR}${PREFIX}/bin/proguard
	${INSTALL_SCRIPT} ${WRKDIR}/proguard-gui.sh ${STAGEDIR}${PREFIX}/bin/proguard-gui
	${INSTALL_SCRIPT} ${WRKDIR}/retrace.sh ${STAGEDIR}${PREFIX}/bin/retrace
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
