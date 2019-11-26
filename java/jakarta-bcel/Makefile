# $FreeBSD$

PORTNAME=	bcel
PORTVERSION=	5.2
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	APACHE_JAKARTA/${PORTNAME}/binaries
PKGNAMEPREFIX=	jakarta-

MAINTAINER=	java@FreeBSD.org
COMMENT=	Library for generating Java bytecode

NO_BUILD=	yes
USE_JAVA=	yes
NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/bcel.jar

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar \
	    ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-not -empty")

.include <bsd.port.mk>
