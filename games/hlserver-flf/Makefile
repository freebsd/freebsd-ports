# New ports collection makefile for:    Front Line Force Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	flf
PORTVERSION=	1.3a
MASTER_SITES=	http://www.flfmod.com/download/ \
		ftp://ftp.task.gda.pl/vol/d33/ftp.extreme-players.de/exp/hl/mod/frontlineforce/ \
		http://www.spies.com/flf/downloads/ \
		http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/half-life/modifications/frontlineforce/
DISTNAME=	frontline${PORTVERSION:S/.//}

WRKSRC=		${WRKDIR}/frontline

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
