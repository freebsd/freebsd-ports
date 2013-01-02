# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	jchessboard
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	games java
MASTER_SITES=	SF
DISTNAME=	JChessBoard-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Chess game and PGN viewer/editor written in Java

LICENSE=	GPLv2

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/${JARFILE}
PLIST_DIRS=	%%DATADIR%%
SUB_FILES=	${PORTNAME}
SUB_LIST+=	JARFILE=${JARFILE} \
		PORTNAME=${PORTNAME}
PORTDOCS=	*

JARFILE=	JChessBoard.jar

.include <bsd.port.options.mk>

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/${JARFILE} ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
