# New ports collection makefile for:	Day of Defeat Half-Life Dedicated Server
# Date created:				Sat Mar 24 00:10:43 EST 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	dod
PORTVERSION=	1.3
MASTER_SITES=	http://www.vigilantegamers.com/dod/files/official/ \
		http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/half-life/modifications/dod/ \
		http://ftp2.extreme-players.de/exp/hl/mod/dod/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/dod/ \
		ftp://ftp.gigabell.net/pub/exp/hl/mod/dod/ \
		http://194.195.228.180/exp/hl/mod/dod/ \
		ftp://mos.eisa.net.au/pub/half-life/dod/linux/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}

WRKSRC=		${WRKDIR}/${PORTNAME}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
