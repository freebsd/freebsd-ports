# New ports collection makefile for:	xpired
# Date created:				2 July 2002
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	xpired
PORTVERSION=	1.22
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xpired
DISTNAME=	${PORTNAME}-${PORTVERSION}-linux_source

MAINTAINER=	edwin@mavetju.org
COMMENT=	An action-puzzle maze escape game (SDL)

USE_SDL=	gfx image mixer sdl
WRKSRC=		${WRKDIR}/src

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xpired ${WRKSRC}/xpiredit ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/img
	@${MKDIR} ${DATADIR}/snd
.for files in xpired.lvl xpired.cfg bgimages.txt readme.txt xpired.dmo
	@${INSTALL_DATA} ${WRKSRC}/${files} ${DATADIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/img/* ${DATADIR}/img
	@${INSTALL_DATA} ${WRKSRC}/snd/* ${DATADIR}/snd

.include <bsd.port.mk>
