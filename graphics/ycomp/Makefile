# New ports collection makefile for:    ycomp
# Date created:         23 Dec 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ycomp
PORTVERSION=	1.3.10
CATEGORIES=	graphics java
MASTER_SITES=	http://www.info.uni-karlsruhe.de/software/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Visualization system for Program Dependency Graphs in VCG format

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	acedemic use only

USE_JAVA=	yes
JAVA_VERSION=	1.5+
USE_BZIP2=	yes
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}-${PORTVERSION}
DATAFILES=	antlr.jar batik.jar graphmlObf.jar yComp.jar yObf.jar \
		ysvgObf.jar

WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	ycomp.sh

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATAFILES} ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/ycomp.sh ${PREFIX}/bin/ycomp

.include <bsd.port.mk>
