# New ports collection makefile for:	multisync
# Date created:			25 Nov 2003
# Whom:				Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	multisync-evolution

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Evolution synchronization plugin for Multisync

BUILD_DEPENDS=	evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	multisync:${PORTSDIR}/deskutils/multisync \
		evolution:${PORTSDIR}/mail/evolution

IGNORE=		does not support Evolution 2. New plugin is in the works and can be obtained from Multisync CVS
EXPIRATION_DATE=2005-02-18
DEPRECATED=	"${IGNORE}"

MD5_FILE=	${MASTERDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

WRKSRC=		${WRKDIR}/multisync-${PORTVERSION}/plugins/evolution_sync

MASTERDIR=	${.CURDIR}/../multisync

.include "${MASTERDIR}/Makefile"
