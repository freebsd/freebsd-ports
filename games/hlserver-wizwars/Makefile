# New ports collection makefile for:	Wizard Wars Server
# Date created:				Fri May	4 17:43:25 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wizardwars
PORTVERSION=	0.1.0
PORTEPOCH=	1
MASTER_SITES=	http://fileplanet.games-world.net/dl/ftp1.gamespy.com/action/half-life/modifications/
DISTNAME=	wizwars_release_${PORTVERSION_PROCESSED:S/./_/}_linux

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=		${WRKDIR}/wizwars

PORTVERSION_PROCESSED=	${PORTVERSION:S/^0.//}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
