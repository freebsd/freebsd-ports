# New ports collection makefile for:	Day of Defeat Half-Life Dedicated Server
# Date created:				Sat Mar 24 00:10:43 EST 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	dod
PORTVERSION=	1.0b
PORTEPOCH=	1
PORTREVISION=	2
PKGNAMEPREFIX=	hlserver-

RUN_DEPENDS=	${PREFIX}${HLDSDIR}${HL_PROGRAM}:${HALFLIFE_PORT_MASTER}

COMMENT=	Half-Life mod Day of Defeat full server package for Linux

HALFLIFE_PORT_MASTER=	${.CURDIR}/../halflifeserver

.include "${HALFLIFE_PORT_MASTER}/Makefile"
