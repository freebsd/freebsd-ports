# Ports collection makefile for:	batik
# Date created:			Feb 25, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	batik
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	graphics java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	xmlgraphics/${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SVG Toolkit

USE_ZIP=	yes
USE_JAVA=	1.5+
USE_ANT=	yes
USE_JIKES=	no
ALL_TARGET=	jars all-jar
# Prevent out of memory error during build
MAKE_ENV+=	"ANT_OPTS=-Xmx512m"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}-${PORTVERSION}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

do-install:
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}

.include <bsd.port.mk>
