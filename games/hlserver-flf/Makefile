# New ports collection makefile for:    Front Line Force Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	flf
PORTVERSION=	1.6
MASTER_SITES=	http://www.flfmod.net/site/info/files/ \
		http://flf.spies.com/files/cur_release/ \
		http://mirror.nuclearfallout.net:113/ \
		http://nephilim.net/files/
DISTNAME=	frontline${PORTVERSION:S/.//}_linux

WRKSRC=		${WRKDIR}/frontline
USE_ZIP=	yes

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
