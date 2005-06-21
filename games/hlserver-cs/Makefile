# New ports collection makefile for:	Counter Strike Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	cs
PORTVERSION=	1.6
PKGNAMEPREFIX=	hlserver-

RUN_DEPENDS=	${PREFIX}${HLDSDIR}${HL_PROGRAM}:${HALFLIFE_PORT_MASTER}

COMMENT=	Half-Life mod Counter-Strike full server package for Linux

HALFLIFE_PORT_MASTER=	${.CURDIR}/../halflifeserver

.include "${HALFLIFE_PORT_MASTER}/Makefile"
