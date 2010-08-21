# New ports collection makefile for:	gish-demo
# Date created:				04 September 2006
# Whom:					Jona Joachim <walkingshadow@grummel.net>
#
# $FreeBSD$
#

PORTNAME=	gish-demo
PORTVERSION=	1.60
CATEGORIES=	games linux
MASTER_SITES=	http://s159260531.onlinehome.us/demos/
DISTNAME=	gishdemo

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A platform game with a gelatinous 12-pound ball of tar named Gish (Demo version)

RESTRICTED=	(c) Copyright 2004 Chronic Logic All rights reserved
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	is an i386 Linux binary
USE_LINUX=	yes
USE_LINUX_APPS=	libvorbis openal-soft
NO_BUILD=	yes
DATADIR=	${PREFIX}/lib/${PORTNAME}
SUB_FILES=	rungish.sh
SUB_LIST=	LINUXBASE=${LINUXBASE}

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	${BRANDELF} -t Linux ${DATADIR}/gishdemo
	${BRANDELF} -t Linux ${DATADIR}/gishdemo
	${INSTALL_SCRIPT} ${WRKDIR}/rungish.sh ${PREFIX}/bin/gish

.include <bsd.port.mk>
