# New ports collection makefile for:	tcpblast
# Version required:	<self contained>
# Date created:		22 August 1994
# Whom:			mr
#
# $Id: Makefile,v 1.10 1995/11/22 11:37:02 asami Exp $
#

DISTNAME=	tcpblast
PKGNAME=	tcpblast-1.0
CATEGORIES=	net benchmarks

NO_EXTRACT=	yes
NO_WRKDIR=	yes

fetch:
	@${DO_NADA}

pre-clean:
	@echo "===>  Pre-clean for ${DISTNAME}"
	@(${RM} -f ${.CURDIR}/tcpblast)
	@(cd ${.CURDIR}/src; make clean)

.include <bsd.port.mk>
