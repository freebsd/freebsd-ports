# New ports collection makefile for:	Vampire Slayer Server
# Date created:				Sun Sep 23 03:23:31 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vs
PORTVERSION=	4.1b
DISTNAME=	${PORTNAME}_l-${PORTVERSION}_full

MAINTAINER=	lioux@FreeBSD.org

_DONT_INCLUDE_MK_=yes

WRKSRC=		${WRKDIR}/VS

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		You must manually fetch the Linux Port distfile\
		(${DISTFILES}) from http://www.fileplanet.com/dl/dl.asp?/planethalflife/vampire/${DISTFILES},\
		place it in ${DISTDIR} and then run make again
.endif

.include <bsd.port.post.mk>
