# New ports collection makefile for:	hattrickorganizer
# Date Created:		17 Jan 2005
# Whom:			Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	hattrickorganizer
PORTVERSION=	1.34
CATEGORIES=	games java
MASTER_SITES=	http://www.wow-auctions.net/ho/download/
DISTNAME=	ho_${PORTVERSION:S/.//g}

MAINTAINER=	lars.engels@0x20.net
COMMENT=	A management tool for Hattrick.org written in Java

BROKEN=		Unfetchable

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

USE_ZIP=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+

SUB_FILES=	hattrickorganizer.sh

do-install:
	cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/hattrickorganizer.sh ${PREFIX}/bin/hattrickorganizer

.include <bsd.port.mk>
