# New ports collection makefile for:	Day of Defeat Half-Life Dedicated Server
# Date created:				Sat Mar 24 00:10:43 EST 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	dod
PORTVERSION=	1.3b
MASTER_SITES=	http://www.existonline.net/files/mirrors/dod/ \
		http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/half-life/modifications/dod/ \
		http://hosting.noxordo.com/~monolith/ \
		http://www.vigilantegamers.com/dod/files/official/ \
		ftp://ftp2.cistron.nl/pub/games/half-life/modifications/dod/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}

WRKSRC=		${WRKDIR}/${PORTNAME}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
