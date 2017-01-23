# Created by: Jona Joachim <walkingshadow@grummel.net>
# $FreeBSD$

PORTNAME=	gish-demo
PORTVERSION=	1.60
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	http://s159260531.onlinehome.us/demos/
DISTNAME=	gishdemo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Platform game with a gelatinous 12-pound ball of tar (Demo version)

RESTRICTED=	(c) Copyright 2004 Chronic Logic All rights reserved
ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	is an i386 Linux binary
USES=		linux
USE_LINUX=	libvorbis openal-soft
NO_BUILD=	yes
DATADIR=	${PREFIX}/lib/${PORTNAME}
SUB_FILES=	rungish.sh
SUB_LIST=	LINUXBASE=${LINUXBASE}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${DATADIR}
	${BRANDELF} -t Linux ${STAGEDIR}${DATADIR}/gishdemo
	${BRANDELF} -t Linux ${STAGEDIR}${DATADIR}/gishdemo
	${INSTALL_SCRIPT} ${WRKDIR}/rungish.sh ${STAGEDIR}${PREFIX}/bin/gish

.include <bsd.port.mk>
