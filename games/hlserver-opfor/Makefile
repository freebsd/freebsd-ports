# New ports collection makefile for:    Opposing Forces Half-Life Dedicated Server
# Date created:			23 Mar 2001
# Whom:				Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	opfor
PORTVERSION=	1.1.0.8
PORTREVISION=	1
MASTER_SITES=	http://downloads.planetmirror.com/pub/bluesnews/half-life/opfor/
DISTNAME=	opfor${PORTVERSION:S/.//g}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Half-Life mod Opposing Forces full server package for Linux

WRKSRC=		${WRKDIR}/gearbox

USE_BZIP2=	yes

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"
