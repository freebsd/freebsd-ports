# New ports collection makefile for:	forkbomb
# Date created:		21 Jan 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	forkbomb
PORTVERSION=	1.2
CATEGORIES=	benchmarks
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/benchmark

MAINTAINER=	hsn@netmag.cz
COMMENT=	System stress testing tool

USE_GETOPT_LONG=yes

MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN8=		forkbomb.8
PLIST_FILES=	sbin/forkbomb

.include <bsd.port.mk>
