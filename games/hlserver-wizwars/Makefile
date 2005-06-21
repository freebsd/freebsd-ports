# New ports collection makefile for:	Wizard Wars Server
# Date created:				Fri May	4 17:43:25 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wizardwars
PORTVERSION=	0.1.0.5
PORTREVISION=	1
PORTEPOCH=	1
MASTER_SITES=	ftp://ftp2.extreme-players.de/hl/mod/wizardwars/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/wizardwars/
#DISTNAME=	wizwars_v${PORTVERSION:S/^0.//}_full
DISTNAME=	wizwars_v${PORTVERSION:S/0.//:S/.//g}_full

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Half-Life mod Wizard Wars full server package for Linux

WRKSRC=		${WRKDIR}/wizwars

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"
