# Created by: nordwick@xcf.berkeley.edu
# $FreeBSD$

PORTNAME=	cup
PORTVERSION=	11b.20160615
CATEGORIES=	java devel
MASTER_SITES=	http://www2.cs.tum.edu/projects/cup/releases/
PKGNAMEPREFIX=	java-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-bin-${PORTVERSION:S|.|-|}

MAINTAINER=	eg@fbsd.lt
COMMENT=	LALR parser generator in Java

LICENSE=	SMLNJ
LICENSE_NAME=	Standard ML of New Jersey License
LICENSE_TEXT=	The text of the license can be obtained from the following URL:\
		http://www2.cs.tum.edu/projects/cup/licence.php
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	java-cup.sh
CUP_VERSION=	${PORTVERSION:R}
SUB_LIST=	CUP_VERSION=${CUP_VERSION}

PLIST_FILES=	bin/java-cup \
		${JAVAJARDIR}/${PKGNAMEPREFIX}${PORTNAME}.jar \
		${JAVAJARDIR}/${PKGNAMEPREFIX}${PORTNAME}-runtime.jar \
		${JAVAJARDIR}/${PKGNAMEPREFIX}${PORTNAME}-${CUP_VERSION}.jar \
		${JAVAJARDIR}/${PKGNAMEPREFIX}${PORTNAME}-${CUP_VERSION}-runtime.jar

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/java-cup.sh ${STAGEDIR}${PREFIX}/bin/java-cup

	${INSTALL_DATA} ${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${CUP_VERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PKGNAMEPREFIX}${PORTNAME}-${CUP_VERSION}.jar
	${LN} -s ${PKGNAMEPREFIX}${PORTNAME}-${CUP_VERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PKGNAMEPREFIX}${PORTNAME}.jar

	${INSTALL_DATA} ${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-${CUP_VERSION}-runtime.jar \
		${STAGEDIR}${JAVAJARDIR}/${PKGNAMEPREFIX}${PORTNAME}-${CUP_VERSION}-runtime.jar
	${LN} -s ${PKGNAMEPREFIX}${PORTNAME}-${CUP_VERSION}-runtime.jar \
		${STAGEDIR}${JAVAJARDIR}/${PKGNAMEPREFIX}${PORTNAME}-runtime.jar

.include <bsd.port.mk>
