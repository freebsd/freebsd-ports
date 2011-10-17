# ports collection makefile for: netty
# Date created:                  2011-01-16
# Whom:                          Mikhail T. <michael@fun-box.ru>
#
# $FreeBSD$
#

PORTNAME=	netty
PORTVERSION=	3.2.3
DISTVERSIONSUFFIX=.Final-dist
CATEGORIES=	java devel
MASTER_SITES=	SF/jboss/Netty%20Project/Netty%20${PORTVERSION}.Final/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Java NIO client server framework

LICENSE=	ASL

USE_JAVA=	yes
USE_BZIP2=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
DATADIR=	${PREFIX}/share/${UNIQUENAME}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.Final

PLIST_FILES=	%%JAVAJARDIR%%/netty-${PORTVERSION}.jar

PORTDATA=	*
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/jar/netty-${PORTVERSION}.Final.jar ${JAVAJARDIR}/netty-${PORTVERSION}.jar
	cd ${WRKSRC} && ${COPYTREE_SHARE} src ${DATADIR}

.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
