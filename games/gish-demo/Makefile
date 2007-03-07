# New ports collection makefile for:	gish-demo
# Date created:				04 September 2006
# Whom:					Jona Joachim <walkingshadow@grummel.net>
#
# $FreeBSD$
#

PORTNAME=	gish-demo
PORTVERSION=	1.4
CATEGORIES=	games linux
MASTER_SITES=	http://s159260531.onlinehome.us/demos/
DISTNAME=	gishdemo

MAINTAINER=	walkingshadow@grummel.net
COMMENT=	A platform game with a gelatinous 12-pound ball of tar named Gish (Demo version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libvorbis.so.0:${PORTSDIR}/audio/linux-libvorbis \
		${LINUXBASE}/usr/lib/libopenal.so.0:${PORTSDIR}/audio/linux-openal \
		${LINUXBASE}/usr/lib/libalut.so.0:${PORTSDIR}/audio/linux-freealut

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	is an i386 Linux binary
USE_LINUX=	yes
NO_BUILD=	yes
DATADIR=	${PREFIX}/lib/${PORTNAME}
SUB_FILES=	rungish.sh
SUB_LIST=	LINUXBASE=${LINUXBASE}

pre-patch:
	${MV} ${WRKDIR}/gish\ demo ${WRKSRC}

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	${BRANDELF} -t Linux ${DATADIR}/gish
	${INSTALL_SCRIPT} ${WRKDIR}/rungish.sh ${PREFIX}/bin/gish

.include <bsd.port.mk>
