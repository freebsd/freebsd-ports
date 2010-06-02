# New ports collection makefile for:    yed
# Date created:                         15 Jan 2010
# Whom:                                 Eugene Mychlo <myc@barev.net>
#
# $FreeBSD$
#

PORTNAME=	yed
PORTVERSION=	3.5.0.1
CATEGORIES=	graphics java
MASTER_SITES=	#
DISTNAME=	yEd-${PORTVERSION}

MAINTAINER=	myc@barev.net
COMMENT=	An editor for graphs and diagrams

USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
RESTRICTED=	Restrictive license

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_FILES=	${PORTNAME}

DOWNLOAD_URL?=	http://www.yworks.com/en/products_download.php?file=${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	you must manually obtain ${DISTNAME}${EXTRACT_SUFX} from\
	'${DOWNLOAD_URL}', place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.html ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
