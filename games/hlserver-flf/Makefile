# New ports collection makefile for:    Front Line Force Server
# Date created:				Sat Mar 10 16:40:06 EST 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	flf
PORTVERSION=	1.8b
MASTER_SITES=	http://nephilim.net/files/

DISTFILES=	frontline${PORTVERSION:S/.//}_full-linux${EXTRACT_SUFX}
COMMENT=	Half-Life mod Frontline Force full server package for Linux

WRKSRC=		${WRKDIR}/frontline

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
