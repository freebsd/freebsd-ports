# New ports collection makefile for:	Vampire Slayer Server
# Date created:				Sun Sep 23 03:23:31 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vs
PORTVERSION=	5.0
PORTREVISION=	1
MASTER_SITES=	ftp://ftp.thaiguy.net/ \
		http://gamefiles.blueyonder.co.uk/blueyondergames/halflife/modifications/vampireslayer/patches/linux/ \
		ftp://ftp.daddeln.de/pub/daddeln.de/halflife/Mods/vampire/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/vampier/v5/ \
		ftp://ftp2.extreme-players.de/hl/mod/vampier/v5/
DISTNAME=	${PORTNAME}_l-${PORTVERSION}_full

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Half-Life mod Vampire Slayer full server package for Linux

WRKSRC=		${WRKDIR}/VS

HALFLIFE_PORT_MASTER=  ${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"
