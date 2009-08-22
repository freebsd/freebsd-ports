# New ports collection makefile for:    openproj
# Date created:         15 Apr 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	openproj
PORTVERSION=	1.4
CATEGORIES=	deskutils editors java
MASTER_SITES=	SF/${PORTNAME}/OpenProj%20Binaries/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A free, open source Project Manager

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}-${PORTVERSION}
DATAFILES=	lib license openproj.jar readme.html

SUB_FILES=	openproj.sh

do-install:
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/openproj.sh ${PREFIX}/bin/openproj

.include <bsd.port.mk>
