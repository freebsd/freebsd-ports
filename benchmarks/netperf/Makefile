# New ports collection makefile for: netperf
# Version required:	2.1.1
# Date created:		19 July 1996
# Whom:			koshy
#
# $Id: Makefile,v 1.3 1996/11/18 11:22:01 asami Exp $
#

DISTNAME=	netperf-2.1pl1
PKGNAME=	netperf-2.1.1
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cup.hp.com/dist/networking/benchmarks/netperf/

MAINTAINER=	pst@freebsd.org

MAKEFILE=	makefile
MAN1=		netperf.1 netserver.1

post-install:
	strip ${PREFIX}/netperf/netperf
	strip ${PREFIX}/netperf/netserver
	${CP} ${WRKSRC}/netperf.man ${PREFIX}/man/man1/netperf.1
	${CP} ${WRKSRC}/netserver.man ${PREFIX}/man/man1/netserver.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/netperf
	${CP} ${WRKSRC}/netperf.ps ${PREFIX}/share/doc/netperf
	gzip -9nf ${PREFIX}/share/doc/netperf/netperf.ps
.endif

.include <bsd.port.mk>
