# New ports collection makefile for: netperf
# Version required:	2.1.1
# Date created:		19 July 1996
# Whom:			koshy
#
# $Id: Makefile,v 1.3 1996/08/03 19:45:55 pst Exp $
#

DISTNAME=	netperf-2.1pl1
PKGNAME=	netperf-2.1.1
CATEGORIES+=	benchmarks
MASTER_SITES=	ftp://ftp.cup.hp.com/dist/networking/benchmarks/netperf/

MAINTAINER=	pst@freebsd.org
MAKEFILE=	makefile

post-install:
	strip ${PREFIX}/netperf/netperf
	strip ${PREFIX}/netperf/netserver
	cp ${WRKSRC}/netperf.man ${PREFIX}/man/man1/netperf.1
	cp ${WRKSRC}/netserver.man ${PREFIX}/man/man1/netserver.1
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/netperf.1
	gzip -9nf ${PREFIX}/man/man1/netserver.1
.endif
.if !defined(NOPORTDOCS)
	mkdir -p ${PREFIX}/share/doc/netperf
	cp ${WRKSRC}/netperf.ps ${PREFIX}/share/doc/netperf
	gzip -9nf ${PREFIX}/share/doc/netperf/netperf.ps
.endif

.include <bsd.port.mk>
