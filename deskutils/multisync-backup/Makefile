# New ports collection makefile for:	multisync-backup
# Date created:			3 Dec 2003
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	multisync-backup

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Multisync backup plugin

RUN_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync

MD5_FILE=	${.CURDIR}/../multisync/distinfo

WRKSRC=		${WRKDIR}/multisync-${PORTVERSION}/plugins/backup_plugin

.include "${.CURDIR}/../multisync/Makefile"
