# New ports collection makefile for:    bonnie
# Version required:     
# Date created:         26 September 1994
# Whom:                 se
#
# $Id: Makefile,v 1.2 1995/07/13 01:09:03 asami Exp $
#

DISTNAME=       Bonnie
PKGNAME=	bonnie-1.0
CATEGORIES+=	benchmarks
MASTER_SITES=   ftp://ftp.sunet.se/pub/benchmark/Bonnie/ \
		ftp://swedishchef.lerc.nasa.gov/drlabs/io/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	se@FreeBSD.org

CFLAGS+=	-static

post-install:
	gzip -9nf ${PREFIX}/man/man1/bonnie.1

.include <bsd.port.mk>
