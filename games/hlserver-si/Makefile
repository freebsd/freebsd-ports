# New ports collection makefile for:	Science and Industry Server
# Date created:				Tue May  1 23:40:46 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	si
PORTVERSION=	0.97.0ra
MASTER_SITES=	ftp://ftp2.extreme-players.de/hl/mod/si/ \
		ftp://ftp.clanserver4u.de/exp/hl/mod/si/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g:S/0r//}-linux

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Half-Life mod Science and Industry full server package for Linux

_DONT_INCLUDE_MK_=yes

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"

.include <bsd.port.mk>
