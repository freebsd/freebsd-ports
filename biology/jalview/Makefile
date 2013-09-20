# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	jalview
PORTVERSION=	2.07
PORTREVISION=	2
CATEGORIES=	biology java
MASTER_SITES=	http://www.jalview.org/source/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A viewer and editor for multiple sequence alignments

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
ALL_TARGET=	makejars
WRKSRC=		${WRKDIR}/${PORTNAME}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
SUB_FILES=	jalview.sh

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jalview.sh ${PREFIX}/bin/jalview
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dist/* ${DATADIR}

.include <bsd.port.mk>
