# New ports collection makefile for:	fconv
# Version required:	0.1
# Date created:		21 April 1999
# Whom:			Chris Costello <chris@calldei.com>
#
# $Id: Makefile,v 1.1.1.1 1999/06/07 04:41:55 taoka Exp $
#

DISTNAME=	fconv-0.1
CATEGORIES=	converters
MASTER_SITES=	http://WWW.FreeBSD.ORG/~taoka/distfiles/

MAINTAINER=	ports@FreeBSD.ORG

ONLY_FOR_ARCHS=	i386

post-install:
	strip ${PREFIX}/bin/dos2bsd
	strip ${PREFIX}/bin/bsd2dos
	strip ${PREFIX}/bin/mac2bsd
	strip ${PREFIX}/bin/bsd2mac

.include <bsd.port.mk>
