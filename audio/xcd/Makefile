# New ports collection makefile for:    xcd
# Date created:         22 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	xcd
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	audio tk
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Tcl/Tk CD player

USE_TK=		yes
WRKSRC=		${WRKDIR}/xcd
MAN1=		xcd.1

.if !defined(WITH_CDROM_PLAYER)
WITH_CDROM_PLAYER=	acd0
.endif

pre-extract:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You can define WITH_CDROM_PLAYER to set the default CD/DVD player"
	@${ECHO_CMD} "Default: acd0"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Use the CDPLAYER environment variable to override it."
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} 's|cd0c|${WITH_CDROM_PLAYER}|' ${WRKSRC}/cdplayer.cc
	@${REINPLACE_CMD} 's|/usr/local/bin/wish8.0|${WISH}|' ${WRKSRC}/xcd.in
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
