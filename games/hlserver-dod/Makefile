# New ports collection makefile for:	Day of Defeat Half-Life Dedicated Server
# Date created:				Sat Mar 24 00:10:43 EST 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	dod
PORTVERSION=	2.0
MASTER_SITES=	http://games.gci.net/pub/Half-Life/Mods/DoD/ \
		http://download.filefront.com/pub2/halflife/mods/day_of_defeat/ \
		ftp://ftpuk.jolt.co.uk/games/halflife/mods/dod/patches/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}

WRKSRC=		${WRKDIR}/${PORTNAME}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
