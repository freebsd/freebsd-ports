# New ports collection makefile for:	multisync
# Date created:			25 Nov 2003
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	multisync-evolution

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Evolution synchronization plugin for Multisync

RUN_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync \
		evolution:${PORTSDIR}/mail/evolution

MD5_FILE=	${.CURDIR}/../multisync/distinfo

WRKSRC=		${WRKDIR}/multisync-${PORTVERSION}/plugins/evolution_sync

.include "${.CURDIR}/../multisync/Makefile"
