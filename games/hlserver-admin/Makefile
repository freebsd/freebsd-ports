# New ports collection makefile for:    Half Life Admin Mod
# Date created:				Sun Apr 29 15:58:33 EDT 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	admin
PORTVERSION=	2.50.09
PORTEPOCH=	1
MASTER_SITES=	http://www.adminmod.org/downloads/
DISTNAME=	halflife-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

WRKSRC=		${WRKDIR}/Admin

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
