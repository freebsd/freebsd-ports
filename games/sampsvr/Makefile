# New ports collection makefile for:	sampsvr
# Date created:				6 November 2006
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	sampsvr
PORTVERSION=	0.1b
CATEGORIES=	games linux
MASTER_SITES=	http://www.sa-mp.com/files/ \
		http://eu.littlewhitey.com/ \
		http://server.safclan.net/upload/
DISTNAME=	${SAMPVER}.linux.cpp6

MAINTAINER=	ports@logvinov.com
COMMENT=	Rockstar's GTA: San Andreas multiplayer modification dedicated server

USE_LINUX=	yes
NO_BUILD=	yes
SAMPVER=	samp01b
USE_RC_SUBR=	sampd
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_SUB=	SAMPDIR="${PORTNAME}"
SUB_FILES=	pkg-message
SUB_LIST=	SAMPDIR="${PREFIX}/${PORTNAME}"

post-patch:
	@${MV} ${WRKSRC}/server.cfg ${WRKSRC}/server.cfg.dist
	@${MV} ${WRKSRC}/${SAMPVER} ${WRKSRC}/${USE_RC_SUBR}

do-install:
	@${CP} -Rp ${WRKSRC}/ ${PREFIX}/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
