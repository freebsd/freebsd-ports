# New ports collection makefile for:	proguard
# Date created:				Apr 19 2003
# Whom:					Alex Semenyaka <alex@rinet.ru>
#
# $FreeBSD$
#

PORTNAME=	proguard
PORTVERSION=	3.2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	alexs@snark.rinet.ru
COMMENT=	Java obfuseeKata

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_JAVA=	yes
NO_BUILD=	yes

SUB_FILES=	proguard.sh proguard-gui.sh

do-install:
	cd ${WRKSRC} && \
	  ${FIND} lib docs examples -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && \
	  ${FIND} lib docs examples -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	${INSTALL_SCRIPT} ${WRKDIR}/proguard.sh ${PREFIX}/bin/proguard
	${INSTALL_SCRIPT} ${WRKDIR}/proguard-gui.sh ${PREFIX}/bin/proguard-gui

.include <bsd.port.mk>
