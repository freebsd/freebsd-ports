# New ports collection makefile for:	tcpblast
# Version required:	<self contained>
# Date created:		22 August 1994
# Whom:			mr
#
# $Id: Makefile,v 1.7 1995/04/15 05:41:58 asami Exp $
#

DISTNAME=	tcpblast
PKGNAME=	tcpblast-1.0
CATEGORIES=	networking

NO_EXTRACT=	yes
NO_WRKDIR=	yes

fetch:
	@${DO_NADA}

pre-clean:
	@echo "===>  Pre-clean for ${DISTNAME}"
	@(rm -f ${.CURDIR}/tcpblast)
	@(cd ${.CURDIR}/src; make clean)

.include <bsd.port.mk>
