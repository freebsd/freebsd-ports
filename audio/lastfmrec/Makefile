# New ports collection makefile for:	lastfmrec
# Date created:				July 13 2008
# Whom:					Tino Engel <goaengel@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	lastfmrec
PORTVERSION=	0.1b
CATEGORIES=	audio
MASTER_SITES=	http://elgrande.daemoncore.org/files/software/

MAINTAINER=	goaengel@gmx.net
COMMENT=	Record last.fm radio to single mp3 files (while playing)

RUN_DEPENDS=	shell-fm:${PORTSDIR}/multimedia/shell-fm \
		vsound:${PORTSDIR}/audio/vsound \
		sox:${PORTSDIR}/audio/sox

MAN1=	lastfmrec.1
PLIST_FILES=	bin/lastfmrec

.include <bsd.port.mk>
