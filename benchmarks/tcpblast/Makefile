# New ports collection makefile for:	tcpblast
# Version required:	<self contained>
# Date created:		22 August 1994
# Whom:			mr
#
# $Id: Makefile,v 1.4 1994/11/17 00:22:54 jkh Exp $
#

DISTNAME=	tcpblast
NO_EXTRACT=	yes
NO_WRKDIR=	yes

pre-clean:
	@echo "===>  Pre-clean for ${DISTNAME}"
	@(rm -f ${.CURDIR}/tcpblast)
	@(cd ${.CURDIR}/src; make clean)

.include <bsd.port.mk>
