# New ports collection makefile for: Electric Fence 
# Version required:	2.0.5
# Date created: 	13 November 1997
# Whom:			jraynard
#
# $Id: Makefile,v 1.3 1997/11/15 10:47:30 asami Exp $
#

DISTNAME=	ElectricFence-2.0.5
PKGNAME=	electricfence-2.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/c

MAINTAINER=	jraynard@freebsd.org

MAN3=		libefence.3

OSVERSION!=	sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=	"During build: ElectricFence Exiting: mmap() failed: Invalid argument"
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/libefence.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/libefence.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
