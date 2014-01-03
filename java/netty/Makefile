# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	netty
PORTVERSION=	3.5.5
DISTVERSIONSUFFIX=.Final-dist
CATEGORIES=	java devel
MASTER_SITES=	https://github.com/downloads/netty/netty/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Java NIO client server framework

LICENSE=	APACHE20

USE_JAVA=	yes
USE_BZIP2=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/${UNIQUENAME}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.Final

PLIST_FILES=	%%JAVAJARDIR%%/netty-${PORTVERSION}.jar \
		%%JAVAJARDIR%%/netty.jar

PORTDATA=	*
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/jar/netty-${PORTVERSION}.Final.jar ${JAVAJARDIR}/netty-${PORTVERSION}.jar
	cd ${WRKSRC} && ${COPYTREE_SHARE} src ${DATADIR}
	${LN} -nfs ${JAVAJARDIR}/netty-${PORTVERSION}.jar ${JAVAJARDIR}/netty.jar

.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
