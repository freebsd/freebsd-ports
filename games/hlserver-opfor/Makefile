# New ports collection makefile for:    Opposing Forces Half-Life Dedicated Server
# Date created:			23 Mar 2001
# Whom:				Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opfor
PORTVERSION=	1.1.0.6
MASTER_SITES=	http://www.planetmirror.com/pub/bluesnews/half-life/opfor/ \
		http://fileplanet.games-world.net/dl/ftp1.gamespy.com/fpnew/action/half-life/official/ \
		http://ftp1download.gamespy.com/fileplanet/fpnew/action/half-life/official/
DISTNAME=	op4-linux-${PORTVERSION:S/.//g}

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=		${WRKDIR}/gearbox

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
