# New ports collection makefile for:	Science and Industry Server
# Date created:				Tue May  1 23:40:46 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	si
PORTVERSION=	0.97.0ra
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g:S/0r//}-linux

MAINTAINER=	lioux@FreeBSD.org

_DONT_INCLUDE_MK_=yes

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		You must manually fetch the Linux Port distfile\
		(${DISTFILES}) from http://www.fileplanet.com/dl/dl.asp?/planethalflife/si/${DISTFILES},\
		place it in ${DISTDIR} and then run make again
.endif

.include <bsd.port.post.mk>
