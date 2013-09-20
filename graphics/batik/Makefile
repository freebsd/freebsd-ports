# Created by: ijliao
# $FreeBSD$

PORTNAME=	batik
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	graphics java
MASTER_SITES=	APACHE/xmlgraphics/${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Java based SVG toolkit

LICENSE=	AL2

USE_ZIP=	yes
USE_JAVA=	1.5+
USE_ANT=	yes
ALL_TARGET=	jars all-jar
# Prevent out of memory error during build
MAKE_ENV+=	"ANT_OPTS=-Xmx512m"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PORTDOCS=	CHANGES NOTICE README

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
