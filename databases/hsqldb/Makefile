PORTNAME=	hsqldb
PORTVERSION=	2.7.4
CATEGORIES=	databases java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_2_7

MAINTAINER=	jim@ohlste.in
COMMENT=	Embeddable SQL database written in Java
WWW=		https://hsqldb.org/

LICENSE=	BSD3CLAUSE

USES=		java:ant,run zip

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/build
ALL_TARGET=	hsqldb sqltool
MAKE_ARGS+=	-Djdk8string=''

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR}  ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/hsqldb.jar \
		${STAGEDIR}${JAVAJARDIR}/hsqldb.jar
	${INSTALL_DATA} ${WRKSRC}/lib/sqltool.jar \
		${STAGEDIR}${JAVAJARDIR}/sqltool.jar

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
