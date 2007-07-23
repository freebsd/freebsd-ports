# New ports collection makefile for:	shntool
# Date created:		2 November 2000
# Whom:			Bill Fenner <fenner@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shntool
PORTVERSION=	3.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/shntool/dist/src/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Multi-purpose .wav processing utility

GNU_CONFIGURE=	yes
SHN_ALIASES=	tool len fix hash pad join split cat cmp cue conv info strip gen trim
PLIST_FILES=	${SHN_ALIASES:S|^|bin/shn|}
MAN1=		shntool.1

.include <bsd.port.mk>
