# New ports collection makefile for:	jalview
# Date created:				11 Jan 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	jalview
PORTVERSION=	2.07
CATEGORIES=	biology java
MASTER_SITES=	http://www.jalview.org/source/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A viewer and editor for multiple sequence alignments

USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
ALL_TARGET=	makejars
WRKSRC=		${WRKDIR}/${PORTNAME}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	jalview.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jalview.sh ${PREFIX}/bin/jalview
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dist/* ${DATADIR}

.include <bsd.port.mk>
