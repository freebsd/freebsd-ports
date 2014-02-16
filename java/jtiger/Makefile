# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	jtiger
PORTVERSION=	2.1.0376
CATEGORIES=	java devel
MASTER_SITES=	http://kaiwitte.org/jtiger/

MAINTAINER=	wenheping@gmail.com
COMMENT=	Unit Test Framework and Tools for the Java2 Platform

USE_JAVA=	1.5
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SRCFILES=	src test-src

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_DATA} ${WRKDIR}/jtiger.jar ${STAGEDIR}${JAVAJARDIR}/jtiger.jar
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKDIR} && ${COPYTREE_SHARE} "${SRCFILES}" ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKDIR}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/changes.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cpl-v10.html ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
