# New ports collection makefile for:    Front Line Force Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	flf
PORTVERSION=	1.7a
MASTER_SITES=	http://www.flfmod.com/download/ \
		http://www.bannie.net/bannie/downloads/mods/flfmod/ \
		http://mirror.nuclearfallout.net:113/ \
		http://nephilim.net/files/ \
		ftp://www.fragland.net/halflife/mods/flf/ \
		ftp://ftp.daddeln.de/pub/hostings/gw.de/other/
DISTFILES=	frontline17_linux${EXTRACT_SUFX} \
		frontline17a_up_linux${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/frontline
USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-o -qq

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
