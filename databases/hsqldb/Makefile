# Created by: Michael Winking <mwfp@foldl.net>
# $FreeBSD$

PORTNAME=	hsqldb
PORTVERSION=	2.3.2
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_2_3

MAINTAINER=	jim@ohlste.in
COMMENT=	Embeddable SQL database written in Java

LICENSE=	BSD3CLAUSE

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/build
ALL_TARGET=	hsqldb hsqljdbc

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR}  ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/hsqldb.jar \
		${STAGEDIR}${JAVAJARDIR}/hsqldb.jar
	${INSTALL_DATA} ${WRKSRC}/lib/hsqljdbc.jar \
		${STAGEDIR}${JAVAJARDIR}/hsqljdbc.jar
	${INSTALL_DATA} ${WRKSRC}/lib/sqltool.jar \
		${STAGEDIR}${JAVAJARDIR}/sqltool.jar

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
