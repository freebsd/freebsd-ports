# New ports collection makefile for:  sfio
# Version required:	2.0.5
# Date created: 	13 November 1997
# Whom:			jraynard
#
# $Id$
#

DISTNAME=	ElectricFence-2.0.5
CATEGORIES=	devel
MASTER_SITES=	MASTER_SITE_LOCAL

MAINTAINER=	jraynard@freebsd.org

MAN3=		libefence.3

#do-build:
#	@cd ${WRKDIR}/src/lib/sfio && ${MAKE} all -f makefile
#	@cd ${WRKDIR}/src/lib/sfdisc && ${MAKE} all

do-install:
	${INSTALL_DATA} ${WRKSRC}/libefence.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/libefence.3 ${PREFIX}/man/man3

.include <bsd.port.mk>
