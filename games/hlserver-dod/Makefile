# New ports collection makefile for:	Day of Defeat Half-Life Dedicated Server
# Date created:				Sat Mar 24 00:10:43 EST 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	dod
PORTVERSION=	3.0
MASTER_SITES=	http://mirror.redphive.org/ \
		ftp://files.recongamer.com/games/action/half-life/mods/dayofdefeat/ \
		ftp://213.186.36.148/ \
		ftp://ftp.skynet.be/games/dod/ \
		ftp://ftp.dod-europe.com/dod/dod/${PORTVERSION}/linux/ \
		ftp://ftp.euroserv.com/pub/halflife/ \
		ftp://ftp.dodfrance.com/dod/dod/${PORTVERSION}/linux/ \
		ftp://213.187.219.201/dod/linux/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}_full

WRKSRC=		${WRKDIR}/${PORTNAME}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
