# New ports collection makefile for:	fconv
# Date created:		21 April 1999
# Whom:			Chris Costello <chris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fconv
PORTVERSION=	0.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	chris

MAINTAINER=	chris@FreeBSD.org

post-install:
	strip ${PREFIX}/bin/dos2bsd
	strip ${PREFIX}/bin/bsd2dos
	strip ${PREFIX}/bin/mac2bsd
	strip ${PREFIX}/bin/bsd2mac

.include <bsd.port.mk>
