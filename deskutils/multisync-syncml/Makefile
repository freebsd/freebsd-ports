# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multisync-syncml

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multisync plugin for SyncML targets

RUN_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync

DISTINFO_FILE=	${MASTERDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

WRKSRC=		${WRKDIR}/multisync-${PORTVERSION}/plugins/syncml_plugin

MASTERDIR=	${.CURDIR}/../multisync

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
