# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	netty
PORTVERSION=	3.10.6
DISTVERSIONSUFFIX=	.Final-dist
CATEGORIES=	java devel
MASTER_SITES=	http://dl.bintray.com/netty/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java NIO client server framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe tar:bzip2
USE_JAVA=	yes
CPE_VENDOR=	netty_project
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.Final

PLIST_FILES=	${JAVAJARDIR}/netty-${PORTVERSION}.jar \
		${JAVAJARDIR}/netty.jar

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/jar/netty-${PORTVERSION}.Final.jar ${STAGEDIR}${JAVAJARDIR}/netty-${PORTVERSION}.jar
	@cd ${WRKSRC} && ${COPYTREE_SHARE} src ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${LN} -nfs netty-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/netty.jar

.include <bsd.port.mk>
