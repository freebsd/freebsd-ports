# New ports collection makefile for:	Global Warfare Server
# Date created:				Sat Jun	9 23:09:24 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glbwar
PORTVERSION=	1.0.0b
MASTER_SITES=	http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/half-life/modifications/globalwarfare/ \
		ftp://ftp.gigabell.net/pub/exp/hl/mod/gw/ \
		ftp://ftp.netgames-uk.net/pub/local/games/halflife/mods/global_warfare/beta1/ \
		http://ftp2.extreme-players.de/exp/hl/mod/gw/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/gw/ \
		http://194.195.228.180/exp/hl/mod/gw/ \
		http://www.dayofdefeat.com/
DISTNAME=	${PORTNAME}_beta1.0_full_official.linux.i386

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=		${WRKDIR}/globalwarfare

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
