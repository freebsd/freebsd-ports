# New ports collection makefile for:	chasen
# Date created:		21 October 1998
# Whom:			kuriyama
#
# $NetBSD: Makefile,v 1.2 1999/06/07 09:54:39 sakamoto Exp $
# $FreeBSD$
#

PORTNAME=	chasen
PORTVERSION=	2.2.9
CATEGORIES=	japanese
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	chasen:${PORTSDIR}/japanese/chasen-base \
		${LOCALBASE}/share/chasen/dic/ipadic/cforms.cha:${PORTSDIR}/japanese/ipadic

NO_BUILD=	YES

do-install:

.include <bsd.port.mk>
