# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	jtiger
PORTVERSION=	2.1.0376
CATEGORIES=	java devel
MASTER_SITES=	http://kaiwitte.org/jtiger/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unit Test Framework and Tools for the Java2 Platform

USE_JAVA=	1.6
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

SRCFILES=	src test-src

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_DATA} ${WRKSRC}/jtiger.jar ${STAGEDIR}${JAVAJARDIR}/jtiger.jar
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${SRCFILES}" ${STAGEDIR}${DATADIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changes.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cpl-v10.html ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
