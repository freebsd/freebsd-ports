# New ports collection makefile for:	multisync-syncml
# Date created:			25 Nov 2003
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	multisync-syncml

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Multisync plugin for SyncML targets

RUN_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync

MD5_FILE=	${MASTERDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

WRKSRC=		${WRKDIR}/multisync-${PORTVERSION}/plugins/syncml_plugin

MASTERDIR=	${.CURDIR}/../multisync

.include "${MASTERDIR}/Makefile"
