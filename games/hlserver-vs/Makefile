# New ports collection makefile for:	Vampire Slayer Server
# Date created:				Sun Sep 23 03:23:31 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vs
PORTVERSION=	3.0
MASTER_SITES=	ftp://ftp2.extreme-players.de/hl/mod/vampier/ \
		http://ftp.gigabell.net/pub/exp/hl/mod/vampier/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/vampier/
DISTNAME=	${PORTNAME}_l-${PORTVERSION}_full

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=		${WRKDIR}/VS

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
