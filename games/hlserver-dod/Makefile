# New ports collection makefile for:	Day of Defeat Half-Life Dedicated Server
# Date created:				Sat Mar 24 00:10:43 EST 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	dod
PORTVERSION=	3.1
MASTER_SITES=	http://www.redphive.org/files/ \
		ftp://gamefiles.blueyonder.co.uk/blueyondergames/halflife/modifications/dayofdefeat/patches/linux/ \
		http://bajar.juegosonline.com/mods/ \
		ftp://ftpuk.jolt.co.uk/games/halflife/mods/dod/patches/ \
		ftp://ftp.dodfrance.com/dod/dod/3.1/linux/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}_full

WRKSRC=		${WRKDIR}/${PORTNAME}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
