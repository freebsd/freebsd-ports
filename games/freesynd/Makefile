# New ports collection makefile for:	freesynd
# Date created:				2007-05-27
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	freesynd
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freesynd

MAINTAINER=	lme@FreeBSD.org
COMMENT=	FreeSynd GPLed reimplementation of the classic Bullfrog game Syndicate

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_ZIP=	yes
USE_SDL=	sdl mixer

WRKSRC=		${WRKDIR}/${PORTNAME}/src

SUB_FILES=	freesynd.sh

do-install:
	${MKDIR} ${DATADIR}/data
	${INSTALL_PROGRAM} ${WRKSRC}/freesynd ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/freesynd.sh ${PREFIX}/bin
	${CP} ${WRKDIR}/${PORTNAME}/assassinate.mp3 ${DATADIR}
.for datafile in ${WRKDIR}/${PORTNAME}/data/*
	${INSTALL_DATA} ${WRKDIR}/${datafile} ${DATADIR}/data
.endfor

.include <bsd.port.mk>
