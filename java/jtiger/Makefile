# New ports collection makefile for:	JTiger
# Date created:		June 1st , 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	jtiger
PORTVERSION=	2.1.0376
CATEGORIES=	java devel
MASTER_SITES=	http://jtiger.org/download/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Unit Test Framework and Tools for the Java2 Platform

USE_JAVA=	1.5
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

SRCFILES=	src test-src

do-install:
	${INSTALL_DATA} ${WRKDIR}/jtiger.jar ${JAVAJARDIR}/jtiger.jar

post-install:
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKDIR} \
		&& ${FIND} ${SRCFILES} -type d -exec ${MKDIR} ${DATADIR}/\{} \; \
		&& ${FIND} ${SRCFILES} -type f -exec ${INSTALL_DATA} \{} ${DATADIR}/\{} \;
.endif

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKDIR}/samples \
		&& ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${EXAMPLESDIR}/\{} \;
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/changes.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/cpl-v10.html ${DOCSDIR}
	cd ${WRKDIR}/doc \
		&& ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/\{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} \{} ${DOCSDIR}/\{} \;
.endif

.include <bsd.port.post.mk>
