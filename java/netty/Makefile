# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	netty
PORTVERSION=	3.9.2
DISTVERSIONSUFFIX=	.Final-dist
CATEGORIES=	java devel
MASTER_SITES=	http://dl.bintray.com/netty/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java NIO client server framework

LICENSE=	APACHE20

USE_JAVA=	yes
USES=		cpe tar:bzip2
CPE_VENDOR=	netty_project
JAVA_VERSION=	1.6+
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.Final

PLIST_FILES=	%%JAVAJARDIR%%/netty-${PORTVERSION}.jar \
		%%JAVAJARDIR%%/netty.jar

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/jar/netty-${PORTVERSION}.Final.jar ${STAGEDIR}${JAVAJARDIR}/netty-${PORTVERSION}.jar
	cd ${WRKSRC} && ${COPYTREE_SHARE} src ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${LN} -nfs netty-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/netty.jar

.include <bsd.port.mk>
