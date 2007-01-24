# New ports collection makefile for:	shntool
# Date created:		2 November 2000
# Whom:			Bill Fenner <fenner@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	shntool
PORTVERSION=	3.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/shntool/dist/src/ CSME LOCAL/fenner

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	Multi-purpose .wav processing utility

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
SHN_ALIASES=	tool len fix hash pad join split cat cmp cue conv info strip gen trim
PLIST_FILES=	${SHN_ALIASES:S|^|bin/shn|}
MAN1=		shntool.1

.include <bsd.port.mk>
