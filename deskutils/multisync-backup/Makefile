# New ports collection makefile for:	multisync-backup
# Date created:			3 Dec 2003
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	multisync-backup

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Multisync backup plugin

RUN_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync

MD5_FILE=	${MASTERDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

WRKSRC=		${WRKDIR}/multisync-${PORTVERSION}/plugins/backup_plugin

MASTERDIR=	${.CURDIR}/../multisync

.include "${MASTERDIR}/Makefile"
