# New ports collection makefile for:	wavplay
# Date created:				14 January 2000
# Whom:					greg
#
# $FreeBSD$
#

PORTNAME=	wavplay
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/sound/players

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A wav player and recorder

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Doesn't work on !i386

MAN1=		wavplay.1

PLIST_FILES=	bin/wavplay bin/wavrec

.include <bsd.port.mk>
