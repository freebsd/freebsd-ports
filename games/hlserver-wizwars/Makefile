# New ports collection makefile for:	Wizard Wars Server
# Date created:				Fri May	4 17:43:25 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wizardwars
PORTVERSION=	0.1.0.5
PORTEPOCH=	1
MASTER_SITES=	ftp://ftp2.extreme-players.de/hl/mod/wizardwars/ \
		http://ftp.gigabell.net/pub/exp/hl/mod/wizardwars/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/wizardwars/ \
		http://www.gamesnetlan.de/files/hl/mods/wizardwars/
#DISTNAME=	wizwars_v${PORTVERSION:S/^0.//}_full
DISTNAME=	wizwars_v${PORTVERSION:S/0.//:S/.//g}_full
#ftp://ftp2.extreme-players.de/hl/mod/wizardwars/wizwars_v105_full.tar.gz

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=		${WRKDIR}/wizwars

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
