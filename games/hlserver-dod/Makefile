# New ports collection makefile for:	Day of Defeat Half-Life Dedicated Server
# Date created:				Sat Mar 24 00:10:43 EST 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	dod
PORTVERSION=	1.0b
PORTEPOCH=	1
MASTER_SITES=	ftp://ftp.clanserver4u.de/exp/hl/mod/dod/ \
		ftp://ftp2.extreme-players.de/hl/mod/dod/ \
		http://mirror.redphive.org/

DISTFILES=	dod_v10_linux${EXTRACT_SUFX} dod_v10b${EXTRACT_SUFX}

COMMENT=	Half-Life mod Day of Defeat full server package for Linux

WRKSRC=		${WRKDIR}/${PORTNAME}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
